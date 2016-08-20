/******************************************************************************
* Project Name		: CE95277 ADC and UART
* File Name			: main.c
* Version 			: **
* Device Used		: CY8C5888LTI-LP097
* Software Used		: PSoC Creator 3.1 SP2
* Compiler    		: ARM GCC 4.8.4, ARM RVDS Generic, ARM MDK Generic
* Related Hardware	: CY8CKIT059 PSoC 5 LP Prototyping Kit 
* Owner				: KLMZ
*
********************************************************************************
* Copyright (2015), Cypress Semiconductor Corporation. All Rights Reserved.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress)
* and is protected by and subject to worldwide patent protection (United
* States and foreign), United States copyright laws and international treaty
* provisions. Cypress hereby grants to licensee a personal, non-exclusive,
* non-transferable license to copy, use, modify, create derivative works of,
* and compile the Cypress Source Code and derivative works for the sole
* purpose of creating custom software in support of licensee product to be
* used only in conjunction with a Cypress integrated circuit as specified in
* the applicable agreement. Any reproduction, modification, translation,
* compilation, or representation of this software except as specified above 
* is prohibited without the express written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH 
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the 
* materials described herein. Cypress does not assume any liability arising out 
* of the application or use of any product or circuit described herein. Cypress 
* does not authorize its products for use as critical components in life-support 
* systems where a malfunction or failure may reasonably be expected to result in 
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of 
* such use and in doing so indemnifies Cypress against all charges. 
*
* Use of this Software may be limited by and subject to the applicable Cypress
* software license agreement. 
*******************************************************************************/

#include <device.h>
#include "stdio.h"
#include "CAN_1_TX_RX_func.c"

/* Project Defines */
#define FALSE  0
#define TRUE   1
#define TRANSMIT_BUFFER_SIZE  50
#define BUFF 64
    uint8 TxMessage1[8];
    uint8 RxMessage1[8];
    uint8 RXDLC1;
    uint8 RxFlag1;
    
typedef struct Sensors {
    uint16 data[BUFF];
    uint32 accumulator;
    int16 mV;
    uint8 number;
    uint8 index;
    uint8 window;
}Sensor;

typedef struct Encoders {
    uint16 data[BUFF];
    float accumulator;
    float rpm;
    uint8 number;
    uint8 index;
    uint8 window;
    uint32 time;
}Encoder;
    
uint32 time = 0;

void GetSample(Sensor * sensor);
void GetRPM(Encoder * encoder);


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  main() performs following functions:
*  1: Starts the ADC and UART components.
*  2: Checks for ADC end of conversion.  Stores latest result in output
*     if conversion complete.
*  3: Checks for UART input.
*     On 'C' or 'c' received: transmits the last sample via the UART.
*     On 'S' or 's' received: continuously transmits samples as they are completed.
*     On 'X' or 'x' received: stops continuously transmitting samples.
*     On 'E' or 'e' received: transmits a dummy byte of data.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void main()
{
    /* Variable to store UART received character */
    uint8 Ch;
    /* Flags used to store transmit data commands */
    uint8 ContinuouslySendData;
    uint8 SendSingleByte;
    /* Transmit Buffer */
    char TransmitBuffer[TRANSMIT_BUFFER_SIZE];
    /* Filtering Variables */
    uint8 i=0;
    uint8 j=0;
    uint16 sampleCount = 0;
    uint32 counter = 0;
    
    uint32 rpm = 0;
    
    Sensor hrs180;
    Sensor hrs090;
    Sensor pot;
    
    Encoder left;
    Encoder right;
    
    left.number = 0;
    right.number = 1;
    
    hrs180.number = 0;
    hrs090.number = 1;
    pot.number = 2;
    
    /* Start the components */
    ADC_SAR_1_Start();
    UART_1_Start();
    AMux_1_Start();
    Encoder_Left_Start();
    Encoder_Right_Start();
    leftEncTimer_Start();
    rightEncTimer_Start();
    AMux_1_FastSelect(0);
    CAN_1_Start();
    CAN_ISR_Start();
    CAN_TIMER_Start();
    
    CYGlobalIntEnable;

    
    /* Initialize Variables */
    ContinuouslySendData = FALSE;
    SendSingleByte = FALSE;
    
    for(i=0;i<BUFF;i++){
        hrs180.data[i] = 0;
        hrs090.data[i] = 0;
        pot.data[i] = 0;
        left.data[i] = 0;
        right.data[i] = 0;
    }
    
    hrs180.mV = 0;
    hrs180.accumulator = 0;
    hrs180.index = 0;
    
    hrs090.mV = 0;
    hrs090.accumulator = 0;
    hrs090.index = 0;
    
    pot.mV = 0;
    pot.accumulator = 0;
    pot.index = 0;
    
    left.accumulator = 0.0;
    left.rpm = 0.0;
    left.index = 0;
    
    right.accumulator = 0.0;
    right.rpm = 0.0;
    right.index = 0;
    
    hrs180.window = 50;
    hrs090.window = 50;
    pot.window = 50;
    left.window = 10;
    right.window = 10;
            
    
    
    /* Send message to verify COM port is connected properly */
    UART_1_PutString("\n\rCOM Port Open\n\r");
    
    for(;;)
    {        
        /* Non-blocking call to get the latest data recieved  */
        Ch = UART_1_GetChar();
        
        /* Set flags based on UART command */
        switch(Ch)
        {
            case 0:
                /* No new data was recieved */
                break;
            case 'C':
            case 'c':
                SendSingleByte = TRUE;
                break;
            case 'S':
            case 's':
                ContinuouslySendData = TRUE;
                break;
            case 'X':
            case 'x':
                ContinuouslySendData = FALSE;
                break;
            default:
                /* Place error handling code here */
                break;    
        }
        
        
        GetSample(&hrs180);
        GetSample(&hrs090);
        GetSample(&pot);
        GetRPM(&left);
        GetRPM(&right);
        
        
      
        
            
        
        TxMessage1[0] = 0xAA;
        TxMessage1[1] = 0xBB;
        TxMessage1[2] = 0xCC;
        TxMessage1[3] = 0xDD;
        TxMessage1[4] = 0xEE;
        TxMessage1[5] = 0xFF;
        TxMessage1[6] = 0x00;
        TxMessage1[7] = 0x11;        
        
        CyDelay(5);            
        //Time_Cnt_WriteCounter(0);
            
            
            
        /* Send data based on last UART command */
        if(SendSingleByte || ContinuouslySendData)
        {
            
            /* Format ADC result for transmition */
            sprintf(TransmitBuffer, "%d, %d, %d\n\r", hrs180.mV, (int)left.rpm, (int)right.rpm);
            /* Send out the data */
            UART_1_PutString(TransmitBuffer);
            /* Reset the send once flag */
            SendSingleByte = FALSE;        
            
        }
        
    }
}

void GetSample( Sensor * sensor){
    
    /*This function applies a moving average filter to the data read by the ADC. Each sensor
    *has an associated sensor struct that contains all necessary variables. The multiplexer
    *is switched such that the intended sensor is read by the ADC. The if loop waits for the
    *ADC to sample and then applies the circular buffer-based moving average.
    *
    *For serial debugging purposes, this function also converts the averaged sensor reading
    *to a millivolt value.
    *
    */
    AMux_1_FastSelect(sensor->number);
    ADC_SAR_1_StartConvert();
    if(ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT))
    {
        sensor->accumulator -= sensor->data[sensor->index];
        sensor->data[sensor->index] = ADC_SAR_1_GetResult16();
        sensor->accumulator += sensor->data[sensor->index];
    }
    sensor->index++;
    if(sensor->index==sensor->window){
        sensor->index = 0;
    }
    
    sensor->mV = ADC_SAR_1_CountsTo_mVolts((sensor->accumulator)/sensor->window);
    
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
    
    
    if(encoder->number == 0){ //calculate left rpm
        encoder->accumulator -= encoder->data[encoder->index];
        encoder->data[encoder->index] = Encoder_Left_ReadCounter();
        Encoder_Left_WriteCounter(0); //clear the pulse counter
        encoder->accumulator += encoder->data[encoder->index];
        
        
        
        encoder->rpm = (encoder->accumulator/encoder->window) * 100000 / (leftEncTimer_ReadCounter());
        leftEncTimer_WriteCounter(0); //clear the microsecond counter
    }
    
    if(encoder->number == 1){ //calculate right rpm
        encoder->accumulator -= encoder->data[encoder->index];
        encoder->data[encoder->index] = Encoder_Right_ReadCounter();
        Encoder_Right_WriteCounter(0); //clear the pulse counter
        encoder->accumulator += encoder->data[encoder->index];
        
        encoder->rpm = (encoder->accumulator/encoder->window) * 100000 / (rightEncTimer_ReadCounter());
        rightEncTimer_WriteCounter(0); //clear the microsecond counter
    }
    
    encoder->index++;
    if(encoder->index >= encoder->window){
        encoder->index = 0;
    }

}
        

    

/* [] END OF FILE */
