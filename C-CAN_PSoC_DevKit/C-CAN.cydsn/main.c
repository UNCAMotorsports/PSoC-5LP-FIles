/******************************************************************************
* C-CAN
* UNCA MOTORSPORTS
*******************************************************************************/

#include <device.h>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "CAN_1_TX_RX_func.c"
#include "C-CAN.h"

/*Debug Defines*/
//#define DEBUG_MULTIRATE

#define LOOP

/* Project Defines */

#define FALSE  0
#define TRUE   1
#define BUFF 64
    
#define TIMER_RATE 500000
     
uint32 timer = 0;

static const uint8 CYCODE window_config[8] = {0,0,0,0,0,0,0,0};
static const bool  CYCODE enable_config[8] = {0,0,0,0,0,0,0,0};
static const uint8 CYCODE rate_config[16]  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

#ifdef LOOP
CY_ISR(SysTick_ISR)
{
    timer++;
    if (timer   % GetRate(&zero.sensor)  == 0) { SetFlag(&zero.sensor,  TRUE); }
    if ((timer) % GetRate(&one.sensor)   == 0) { SetFlag(&one.sensor,   TRUE); }
    if ((timer) % GetRate(&two.sensor)   == 0) { SetFlag(&two.sensor,   TRUE); }
    if ((timer) % GetRate(&three.sensor) == 0) { SetFlag(&three.sensor, TRUE); }
    if ((timer) % GetRate(&four.sensor)  == 0) { SetFlag(&four.sensor,  TRUE); }
    if ((timer) % GetRate(&five.sensor)  == 0) { SetFlag(&five.sensor,  TRUE); }
    if ((timer) % GetRate(&left.sensor)  == 0) { SetFlag(&left.sensor,  TRUE); }
    if ((timer) % GetRate(&right.sensor) == 0) { SetFlag(&right.sensor, TRUE); }
    //if ((timer) % 500 == 0) { Config();}
    if (timer >= TIMER_RATE)        { timer = 0; }
}
#endif

int main()
{
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
    
    #ifdef LOOP
    /*Point the Systick vector to the ISR in this file */
    CyIntSetSysVector(SYSTICK_INTERRUPT_VECTOR_NUMBER, SysTick_ISR);
    
    /* Set the number of ticks between interrupts.
    Ignore the function success/fail return value.
    Defined in auto-generated core_cm3.h */
    (void)SysTick_Config(CLOCK_FREQ / INTERRUPT_FREQ); 
    #endif
    
    CYGlobalIntEnable;

    
    /* Initialize Variables */
    
    PotInit(&zero);
    PotInit(&one);
    PotInit(&two);
    PotInit(&three);
    PotInit(&four);
    PotInit(&five);
    EncoderInit(&left);
    EncoderInit(&right);
    
    SensorEnable(&zero.sensor, TRUE);
    SensorEnable(&one.sensor, TRUE);
    SensorEnable(&two.sensor, FALSE);
    SensorEnable(&three.sensor, FALSE);
    SensorEnable(&four.sensor, FALSE);
    SensorEnable(&five.sensor, FALSE);
    SensorEnable(&left.sensor, TRUE);
    SensorEnable(&right.sensor, TRUE);
    
    SensorSet(&zero.sensor,  0, 50, 1); //sensor, number, window, rate.
    SensorSet(&one.sensor,   1, 50, 1);
    SensorSet(&two.sensor,   2, 1, 1);
    SensorSet(&three.sensor, 3, 1, 1);
    SensorSet(&four.sensor,  4, 1, 1);
    SensorSet(&five.sensor,  5, 1, 1);
    SensorSet(&left.sensor,  6, 10, 1);
    SensorSet(&right.sensor, 7, 10, 1);
            
    
    
    /* Send message to verify COM port is connected properly */
    UART_1_PutString("\n\rCOM Port Open\n\r");
    
    for(;;){
        
        Config();
        #ifdef LOOP
        if((zero.sensor.flag==TRUE)&&(zero.sensor.enable==TRUE)){
            GetSample(&zero);
        }
        else if((one.sensor.flag==TRUE)&&(one.sensor.enable==TRUE)){
            GetSample(&one);
        }
        else if((two.sensor.flag==TRUE)&&(two.sensor.enable==TRUE)){
            GetSample(&two);
        }
        else if((three.sensor.flag==TRUE)&&(three.sensor.enable==TRUE)){
            GetSample(&three);
        }
        else if((four.sensor.flag==TRUE)&&(four.sensor.enable==TRUE)){
            GetSample(&four);
        }
        else if((five.sensor.flag==TRUE)&&(five.sensor.enable==TRUE)){
            GetSample(&five);
        }
        else if((left.sensor.flag==TRUE)&&(left.sensor.enable==TRUE)){
            GetRPM(&left);
        }
        else if((right.sensor.flag==TRUE)&&(right.sensor.enable==TRUE)){
            GetRPM(&right);
            
        }
        #endif
    }
}



/* [] END OF FILE */
