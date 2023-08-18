#ifndef __GPIO_INTERFACE_H__
#define __GPIO_INTERFACE_H__


typedef struct
{
    volatile u32 MODER;   // Mode register
    volatile u16 OTYPER;  // Output type register
    volatile u16 rev0;    // Padding two bytes
    volatile u32 OSPEEDR; // Output speed register
    volatile u32 PUPDR;   // Pull-up/pull-down register
    volatile u16 IDR;     // Input data register
    u16 reservedl;        // Padding two bytes
    volatile u16 ODR;     // Output data register
    u16 reserved2;        // Padding two bytes
    volatile u16 BSRRL;   // Bit set/reset register(low)
    volatile u16 BSRRH;   // Bit set/reset register(high)
    volatile u32 LCKR;    // Configuration lock register
    volatile u32 AFR[2];  // Alternate function registers
    // volatile u32 BRR;     // Bit reset register
    // volatile u32 ASCR;    // Analog switch control register
}GPIO_t;

void GPIO_voidSetPinMode(volatile GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8PinMode);
void GPIO_voidSetOutPutPinType(volatile GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8PinMode);
void GPIO_voidSetPinSpeed(volatile GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8PinSpeed);
void GPIO_voidToggleOutputPin(volatile GPIO_t *GPIOx, u8 Copy_u8PinID);
void GPIO_voidSetPuPdConfig(volatile GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8PUPDType);

void GPIO_voidSetPinValue(volatile GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8Value);
void GPIO_voidSetPinValueAtomicAccess(volatile GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8SetRstType);
void GPIO_voidSetPortValue(volatile GPIO_t *GPIOx, u32 Copy_u32Value);
u8 GPIO_u8GetPinValue(volatile GPIO_t *GPIOx, u8 Copy_u8PinID);

//GPIO PORTS
#define GPIOA ((volatile GPIO_t *)0x40020000)
#define GPIOB ((volatile GPIO_t *)0x40020400)
#define GPIOC ((volatile GPIO_t *)0x40020800)

#define ERROR_VAL 255

//Pin modes
#define INPUT 0
#define OUTPUT 1
#define AF 2
#define ANALOG 3

//Pin output modes
#define OUTPUT_PP 0 //Push pull mode
#define OUTPUT_OD 1 //OPEN drain mode

//Pin speed modes
#define LS 0
#define MS 1
#define HS 2

//Pin input modes
#define INPUT_FLOAT 0
#define INPUT_PULL_UP 1
#define INPUT_PULL_DOWN 2

//Pin output modes
#define OUTPUT_LOW 0
#define OUTPUT_HIGH 1

//Pin output modes for atomic access
#define OUTPUT_SET 0
#define OUTPUT_RESET 1

//Pins
#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7
#define Pin8 8
#define Pin9 9
#define Pin10 10
#define Pin11 11
#define Pin12 12
#define Pin13 13
#define Pin14 14
#define Pin15 15

#endif // __GPIO_INTERFACE_H__