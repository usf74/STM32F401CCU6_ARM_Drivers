#ifndef __S7_PRIVATE_H__
#define __S7_PRIVATE_H__

#define S7_ON   OUTPUT_LOW
#define S7_OFF  OUTPUT_HIGH

u8 Numbers_Decode[]= {0b00000001/*0*/,0b01001111/*1*/,0b00010010/*2*/,0b00000110/*3*/,0b01001100/*4*/,0b00100100/*5*/,0b00100000/*6*/,0b00001111/*7*/,0b00000000/*8*/,0b00000100/*9*/};
/*u8 S7_Num0 = 0b00000001;
u8 S7_Num1 = 0b01111001;
u8 S7_Num2 = 0b00100100;
u8 S7_Num3 = 0b00110000;
u8 S7_Num4 = 0b01001100;
u8 S7_Num5 = 0b00010010;
u8 S7_Num6 = 0b00000010;
u8 S7_Num7 = 0b01111000;
u8 S7_Num8 = 0b00000000;
u8 S7_Num9 = 0b00010000;*/

/*#define NUM1A S7_OFF
#define NUM1B S7_OFF
#define NUM1C S7_OFF
#define NUM1D S7_OFF
#define NUM1E S7_OFF
#define NUM1F S7_OFF
#define NUM1G S7_OFF
#define NUM1DOT S7_OFF*/

#endif // __S7_PRIVATE_H__