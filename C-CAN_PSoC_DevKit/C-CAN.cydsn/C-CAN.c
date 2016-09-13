/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <C-CAN.h>

void GetSample( Pot * pot){
    
    /*This function applies a moving average filter to the data read by the ADC. Each sensor
    *has an associated sensor struct that contains all necessary variables. The multiplexer
    *is switched such that the intended sensor is read by the ADC. The if loop waits for the
    *ADC to sample and then applies the circular buffer-based moving average.
    *
    *For serial debugging purposes, this function also converts the averaged sensor reading
    *to a millivolt value.
    *
    */
    AMux_1_FastSelect(pot->sensor.number);
    ADC_SAR_1_StartConvert();
    if(ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT))
    {
        pot->sensor.accumulator -= pot->sensor.data[pot->sensor.index];
        pot->sensor.data[pot->sensor.index] = ADC_SAR_1_GetResult16();
        pot->sensor.accumulator += pot->sensor.data[pot->sensor.index];
    }
    pot->sensor.index++;
    if(pot->sensor.index==pot->sensor.window){
        pot->sensor.index = 0;
    }
    
    pot->mV = ADC_SAR_1_CountsTo_mVolts((pot->sensor.accumulator)/pot->sensor.window);
    
    pot->sensor.flag = FALSE;

    #ifdef DEBUG_MULTIRATE
    UART_1_PutString("\n\rPot ");
    UART_1_PutChar(pot->sensor.number+48);
    UART_1_PutString("\n\r");
    #endif
    
    

    
}

void GetRPM(Encoder * encoder){
    
    /*This function applies a moving average filter to the number of encoder pulses
    *counted by an encoder counter. Each encoder has an encoder struct that contains
    *all of the relevant variables for an encoder. 
    *
    *The moving average filter implemented is the "shortcut" version, making use of a circular
    *buffer to keep things speeds. 
    *
    *Each encoder has an associated hardware pulse counter and time counter. As of 8/19/16
    *the time counter counts microseconds and the encoders are 600ppr. 
    
    *RPM is calculated as follows:
    *(pulses)*(1 rev/600 pulses)*(1/microseconds)*(10^6 microseconds/second)*(60 seconds/minute)=rpm
    *
    *This simplifies to (pulses * 100000) / (microseconds elapsed)
    *
    *With the current setup, the time counter does not reset and can only handle ~65milliseconds.
    *
    */
    
    
    if(encoder->sensor.number == 0){ //calculate left rpm
        encoder->sensor.accumulator -= encoder->sensor.data[encoder->sensor.index];
        encoder->sensor.data[encoder->sensor.index] = Encoder_Left_ReadCounter();
        Encoder_Left_WriteCounter(0); //clear the pulse counter
        encoder->accumulator += encoder->sensor.data[encoder->sensor.index];
        
        
        
        encoder->rpm = (encoder->accumulator/encoder->sensor.window) * 100000 / (leftEncTimer_ReadCounter());
        leftEncTimer_WriteCounter(0); //clear the microsecond counter
    }
    
    if(encoder->sensor.number == 1){ //calculate right rpm
        encoder->sensor.accumulator -= encoder->sensor.data[encoder->sensor.index];
        encoder->sensor.data[encoder->sensor.index] = Encoder_Right_ReadCounter();
        Encoder_Right_WriteCounter(0); //clear the pulse counter
        encoder->accumulator += encoder->sensor.data[encoder->sensor.index];
        
        encoder->rpm = (encoder->accumulator/encoder->sensor.window) * 100000 / (rightEncTimer_ReadCounter());
        rightEncTimer_WriteCounter(0); //clear the microsecond counter
    }
    
    encoder->sensor.index++;
    if(encoder->sensor.index >= encoder->sensor.window){
        encoder->sensor.index = 0;
    }
    
    encoder->sensor.flag = FALSE;
    
    #ifdef DEBUG_MULTIRATE
    UART_1_PutString("\n\rEncoder ");
    UART_1_PutChar(encoder->sensor.number+48);
    UART_1_PutString("\n\r");
    #endif

}

void SensorSet(Sensor * sensor, uint8 number_set, uint8 window_set, uint16 rate_set){
    sensor->number = number_set;
    sensor->window = window_set;
    sensor->rate = rate_set;
    if(window_set>=BUFF){
        sensor->window = BUFF;
    }
}

void PotInit(Pot * pot){
    int i = 0;
    pot->sensor.accumulator = 0;
    pot->mV = 0;
    pot->sensor.index = 0;
    pot->sensor.flag = 0;
    for(i=0;i<BUFF;i++){
        pot->sensor.data[i]=0;
    }
}

void EncoderInit(Encoder * encoder){
    int i = 0;
    encoder->accumulator = 0;
    encoder->rpm = 0;
    encoder->sensor.index = 0;
    encoder->sensor.flag = 0;
    for(i=0;i<BUFF;i++){
        encoder->sensor.data[i]=0;
    }
}

void Config(void){
    uint8 i = 0;
    char ch = 0;
    char config[7] = {'c','o','n','f','i','g','\0'};
    char transmit[TRANSMIT_BUFFER_SIZE];
    
    static char RxBuffer[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    static uint8 RxBufferIndex = 0;
    while(UART_1_GetRxBufferSize()){
	    //sprintf(transmit,"%d",UART_1_GetRxBufferSize());
        //UART_1_PutString(transmit);
        RxBuffer[RxBufferIndex] = UART_1_ReadRxData();
        UART_1_PutChar(RxBuffer[RxBufferIndex]);
        if(RxBufferIndex >= 31) RxBufferIndex = 0;
        RxBufferIndex++;
	}
    
    if((RxBuffer[RxBufferIndex-1] == EOM_CR) || (RxBuffer[RxBufferIndex-1] == EOM_LF)){
        
        RxBuffer[RxBufferIndex-1] = '\0';
        /*
        sprintf(transmit,"\n\r%d\n\r",RxBufferIndex);
        UART_1_PutString(transmit);
        UART_1_PutString(RxBuffer);
        sprintf(transmit,"\n\r");
        UART_1_PutString(transmit);
        UART_1_PutString(config);
        */
        if(memcmp(RxBuffer,config,7)==0){
            
            EnableSave(&zero.sensor);
            EnableSave(&one.sensor);
            EnableSave(&two.sensor);
            EnableSave(&three.sensor);
            EnableSave(&four.sensor);
            EnableSave(&five.sensor);
            EnableSave(&left.sensor);
            EnableSave(&right.sensor);
            
            SensorEnable(&zero.sensor,  FALSE);
            SensorEnable(&one.sensor,   FALSE);
            SensorEnable(&two.sensor,   FALSE);
            SensorEnable(&three.sensor, FALSE);
            SensorEnable(&four.sensor,  FALSE);
            SensorEnable(&five.sensor,  FALSE);
            SensorEnable(&left.sensor,  FALSE);
            SensorEnable(&right.sensor, FALSE);
            
            //RxBufferIndex = 0;
            for(i=0;i<32;i++){
                RxBuffer[i] = 0;
            }
            
            sprintf(transmit,"\n\rPrint current config? Y/N\n\r");
            UART_1_PutString(transmit);
            
            //RxBufferIndex = 0;
            //while(!UART_1_GetRxBufferSize());
            while(1){
                while(UART_1_GetRxBufferSize()){
                    ch = UART_1_ReadRxData();
                    UART_1_PutChar(ch);
                    if((ch=='Y')||(ch=='y')){
                        sprintf(transmit,"\n\rEnable, Rate, Window.\n\r");
                        UART_1_PutString(transmit);
                        sprintf(transmit,"\n\rSensor Zero:   %d, %d, %d\n\r",zero.sensor.enable,zero.sensor.rate,zero.sensor.window);
                        UART_1_PutString(transmit);
                        sprintf(transmit,"\n\rSensor One:    %d, %d, %d\n\r",one.sensor.enable,one.sensor.rate,one.sensor.window);
                        UART_1_PutString(transmit);
                        sprintf(transmit,"\n\rSensor Two:    %d, %d, %d\n\r",two.sensor.enable,two.sensor.rate,two.sensor.window);
                        UART_1_PutString(transmit);
                        sprintf(transmit,"\n\rSensor Three:  %d, %d, %d\n\r",three.sensor.enable,three.sensor.rate,three.sensor.window);
                        UART_1_PutString(transmit);
                        sprintf(transmit,"\n\rSensor Four:   %d, %d, %d\n\r",four.sensor.enable,four.sensor.rate,four.sensor.window);
                        UART_1_PutString(transmit);
                        sprintf(transmit,"\n\rSensor Five:   %d, %d, %d\n\r",five.sensor.enable,five.sensor.rate,five.sensor.window);
                        UART_1_PutString(transmit);
                        sprintf(transmit,"\n\rLeft Encoder:  %d, %d, %d\n\r",left.sensor.enable,left.sensor.rate,left.sensor.window);
                        UART_1_PutString(transmit);
                        sprintf(transmit,"\n\rRight Encoder: %d, %d, %d\n\r",right.sensor.enable,right.sensor.rate,right.sensor.window);
                        UART_1_PutString(transmit);
                        break;
                }
 
            }
                        
        }
        
    }
    
    //RxBufferIndex++;

    }
}

void CAN_Send(uint8 zero, uint8 one, uint8 two, uint8 three, uint8 four, uint8 five, uint8 six, uint8 seven){
    TxMessage1[0] = zero;
    TxMessage1[1] = one;
    TxMessage1[2] = two;
    TxMessage1[3] = three;
    TxMessage1[4] = four;
    TxMessage1[5] = five;
    TxMessage1[6] = six;
    TxMessage1[7] = seven;
}
    
void SetFlag(Sensor * sensor, bool flag_set){
    sensor->flag = flag_set;
}

uint16 GetRate(Sensor * sensor){
    return INTERRUPT_FREQ/(sensor->rate);
}

void SensorEnable(Sensor * sensor, bool enable_set){
    sensor->enable = enable_set;
}

void EnableSave(Sensor * sensor){
    temp_enable[sensor->number] = sensor->enable;
}

void EnableRestore(Sensor * sensor){
    sensor->enable = temp_enable[sensor->number];
}


/* [] END OF FILE */
