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
#define SYSTICK_INTERRUPT_VECTOR_NUMBER 15u  //SysTick defines
#define CLOCK_FREQ BCLK__BUS_CLK__HZ
#define INTERRUPT_FREQ 100000u
#define FALSE  0
#define TRUE   1
#define TRANSMIT_BUFFER_SIZE  50
#define BUFF 64
    uint8 TxMessage1[8];
    uint8 RxMessage1[8];
    uint8 RXDLC1;
    uint8 RxFlag1;
#define TIMER_RATE 100000
    
typedef unsigned char bool;
    
typedef struct Sensors {
    uint16 data[BUFF];
    uint32 accumulator;
    int16 mV;
    uint8 number;
    uint8 index;
    uint8 window;
    bool flag;
    uint16 rate;
}Sensor;

typedef struct Encoders {
    uint16 data[BUFF];
    float accumulator;
    float rpm;
    uint8 number;
    uint8 index;
    uint8 window;
    uint32 time;
    bool flag;
    uint16 rate;
}Encoder;
    
void GetSample(Sensor * sensor);
void GetRPM(Encoder * encoder);
void SensorSet(Sensor * sensor, uint8 number_set, uint8 window_set, uint16 rate_set);
void EncoderSet(Encoder * encoder, uint8 number_set, uint8 window_set, uint16 rate_set);
void SensorInit(Sensor * sensor);
void EncoderInit(Encoder * encoder);
void CAN_Send(uint8 zero, uint8 one, uint8 two, uint8 three, uint8 four, uint8 five, uint8 six, uint8 seven);
void SetEncoderFlag(Encoder * encoder, bool flag_set);
void SetSensorFlag(Sensor * sensor, bool flag_set);
uint16 GetEncoderRate(Encoder * encoder);
uint16 GetSensorRate(Sensor * sensor);

uint32 timer=0;

Sensor steering;
Sensor throttle;
Encoder left;
Encoder right;

CY_ISR(SysTick_ISR)
{
    timer++;
    if (timer     % GetSensorRate(&throttle) == 0) { SetSensorFlag(&throttle, TRUE); }
    if ((timer+1) % GetSensorRate(&steering) == 0) { SetSensorFlag(&steering, TRUE); }
    if ((timer+2) % GetEncoderRate(&left)    == 0) { SetEncoderFlag(&left, TRUE); }
    if ((timer+3) % GetEncoderRate(&right)   == 0) { SetEncoderFlag(&right, TRUE); }
    if (timer >= TIMER_RATE)        { timer = 0; }
    /* no need to clear interrupt source */
}

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
    
    SensorInit(&steering);
    SensorInit(&throttle);
    EncoderInit(&left);
    EncoderInit(&right);
    
    /*Point the Systick vector to the ISR in this file */
    CyIntSetSysVector(SYSTICK_INTERRUPT_VECTOR_NUMBER, SysTick_ISR);
    
    /* Set the number of ticks between interrupts.
    Ignore the function success/fail return value.
    Defined in auto-generated core_cm3.h */
    (void)SysTick_Config(CLOCK_FREQ / INTERRUPT_FREQ); 

    
    CYGlobalIntEnable;

    
    /* Initialize Variables */
    ContinuouslySendData = FALSE;
    SendSingleByte = FALSE;

    SensorSet(&steering, 0, 50, 200);
    SensorSet(&throttle, 1, 50, 200);
    
    EncoderSet(&left, 0, 10, 200);
    EncoderSet(&right, 1, 10, 200);
            
    
    
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
        
        if(steering.flag==TRUE){
            GetSample(&steering);
        }
        else if(throttle.flag==TRUE){
            GetSample(&throttle);
        }
        else if(left.flag==TRUE){
            GetRPM(&left);
        }
        else if(right.flag==TRUE){
            GetRPM(&right);
        }
        
        /* Send data based on last UART command */
        if(SendSingleByte || ContinuouslySendData)
        {
            
            /* Format ADC result for transmition */
            sprintf(TransmitBuffer, "%d, %d, %d\n\r", steering.mV, (int)left.rpm, (int)right.rpm);
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
    
    sensor->rate = FALSE;
    
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
    
    encoder->flag = FALSE;

}

void SensorSet(Sensor * sensor, uint8 number_set, uint8 window_set, uint16 rate_set){
    sensor->number = number_set;
    sensor->window = window_set;
    sensor->rate = rate_set;
    if(window_set>=BUFF){
        sensor->window = BUFF;
    }
}

void EncoderSet(Encoder * encoder, uint8 number_set, uint8 window_set, uint16 rate_set){
    encoder->number = number_set;
    encoder->window = window_set;
    encoder->rate = rate_set;
    if(window_set>=BUFF){
        encoder->window = BUFF;
    }
}

void SensorInit(Sensor * sensor){
    int i = 0;
    sensor->accumulator = 0;
    sensor->mV = 0;
    sensor->index = 0;
    sensor->flag = 0;
    for(i=0;i<BUFF;i++){
        sensor->data[i]=0;
    }
}

void EncoderInit(Encoder * encoder){
    int i = 0;
    encoder->accumulator = 0;
    encoder->rpm = 0;
    encoder->index = 0;
    encoder->flag = 0;
    for(i=0;i<BUFF;i++){
        encoder->data[i]=0;
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
    
void SetEncoderFlag(Encoder * encoder, bool flag_set){
    encoder->flag = flag_set; 
}

void SetSensorFlag(Sensor * sensor, bool flag_set){
    sensor->flag = flag_set;
}

uint16 GetEncoderRate(Encoder * encoder){
    return INTERRUPT_FREQ/(encoder->rate);
}

uint16 GetSensorRate(Sensor * sensor){
    return INTERRUPT_FREQ/(sensor->rate);
}

/* [] END OF FILE */
