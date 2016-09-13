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

#include <project.h>  
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define BUFF 64
#define FALSE  0
#define TRUE   1
#define SYSTICK_INTERRUPT_VECTOR_NUMBER 15u  //SysTick defines
#define CLOCK_FREQ BCLK__BUS_CLK__HZ
#define INTERRUPT_FREQ 50000u
#define TRANSMIT_BUFFER_SIZE  80
#define EOM_CR        0x0D    //message separator char (\r)
#define EOM_LF        0x0A    //message separator char (\n)

    

typedef unsigned char bool;







typedef struct Sensors {
    char name[17];
    uint16 data[BUFF];
    uint32 accumulator;
    uint8 number;
    uint8 index;
    uint8 window;
    bool flag;
    bool enable;
    uint16 rate;
}Sensor;

typedef struct Pots {
    Sensor sensor;
    int16 mV;
}Pot;

typedef struct Encoders {
    Sensor sensor;
    float accumulator;
    float rpm;
}Encoder;

Pot zero;
Pot one;
Pot two;
Pot three;
Pot four;
Pot five;
Encoder left;
Encoder right;

static bool temp_enable[8];

uint8 TxMessage1[8];
uint8 RxMessage1[8];
uint8 RXDLC1;
uint8 RxFlag1;


void GetSample(Pot * pot);
void GetRPM(Encoder * encoder);
void SensorSet(Sensor * sensor, uint8 number_set, uint8 window_set, uint16 rate_set);
void PotInit(Pot * pot);
void EncoderInit(Encoder * encoder);
void CAN_Send(uint8 zero, uint8 one, uint8 two, uint8 three, uint8 four, uint8 five, uint8 six, uint8 seven);
void SetFlag(Sensor * sensor, bool flag_set);
uint16 GetRate(Sensor * sensor);
void SensorEnable(Sensor * sensor, bool enable_set);
void Config(void);
void EnableSave(Sensor * sensor);
void EnableRestore(Sensor * sensor);


/* [] END OF FILE */
