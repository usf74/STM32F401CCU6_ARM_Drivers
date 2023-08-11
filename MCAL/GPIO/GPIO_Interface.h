#ifndef __GPIO_INTERFACE_H__
#define __GPIO_INTERFACE_H__

void GPIO_voidSetPinMode(GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8PinMode);
void GPIO_voidSetOutPutPinType(GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8PinMode);
void GPIO_voidSetPinSpeed(GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8PinSpeed);

void GPIO_voidSetPuPdConfig(GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8PUPDType);

void GPIO_voidSetPinValue(GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8Value);
void GPIO_voidSetPinValueAtomicAccess(GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8SetRstType);
void GPIO_voidSetPortValue(GPIO_t *GPIOx, u32 Copy_u32Value);
u8 GPIO_u8GetPinValue(GPIO_t *GPIOx, u8 Copy_u8PinID);

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