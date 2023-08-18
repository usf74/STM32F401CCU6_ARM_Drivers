
#include "std_types.h"
#include "Bit_Math.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"

#include "LED_Private.h"
#include "LED_Interface.h"
#include "LEDS_Config.h"

void LED_voidInit()
{
    GPIO_voidSetPinMode(LED0_PORT, LED0_Pin, OUTPUT);
    GPIO_voidSetPinMode(LED1_PORT, LED1_Pin, OUTPUT);
    GPIO_voidSetPinMode(LED2_PORT, LED2_Pin, OUTPUT);
    GPIO_voidSetPinMode(LED3_PORT, LED3_Pin, OUTPUT);
    GPIO_voidSetPinMode(LED4_PORT, LED4_Pin, OUTPUT);
    GPIO_voidSetPinMode(LED5_PORT, LED5_Pin, OUTPUT);
    GPIO_voidSetPinMode(LED6_PORT, LED6_Pin, OUTPUT);
    GPIO_voidSetPinMode(LED7_PORT, LED7_Pin, OUTPUT);

    GPIO_voidSetOutPutPinType(LED0_PORT, LED0_Pin, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(LED1_PORT, LED1_Pin, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(LED2_PORT, LED2_Pin, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(LED3_PORT, LED3_Pin, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(LED4_PORT, LED4_Pin, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(LED5_PORT, LED5_Pin, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(LED6_PORT, LED6_Pin, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(LED7_PORT, LED7_Pin, OUTPUT_PP);

    GPIO_voidSetPinSpeed(LED0_PORT, LED0_Pin, LS);
    GPIO_voidSetPinSpeed(LED1_PORT, LED1_Pin, LS);
    GPIO_voidSetPinSpeed(LED2_PORT, LED2_Pin, LS);
    GPIO_voidSetPinSpeed(LED3_PORT, LED3_Pin, LS);
    GPIO_voidSetPinSpeed(LED4_PORT, LED4_Pin, LS);
    GPIO_voidSetPinSpeed(LED5_PORT, LED5_Pin, LS);
    GPIO_voidSetPinSpeed(LED6_PORT, LED6_Pin, LS);
    GPIO_voidSetPinSpeed(LED7_PORT, LED7_Pin, LS);

    GPIO_voidSetPinValueAtomicAccess(LED0_PORT, LED0_Pin, OUTPUT_RESET);
    GPIO_voidSetPinValueAtomicAccess(LED1_PORT, LED1_Pin, OUTPUT_RESET);
    GPIO_voidSetPinValueAtomicAccess(LED2_PORT, LED2_Pin, OUTPUT_RESET);
    GPIO_voidSetPinValueAtomicAccess(LED3_PORT, LED3_Pin, OUTPUT_RESET);
    GPIO_voidSetPinValueAtomicAccess(LED4_PORT, LED4_Pin, OUTPUT_RESET);
    GPIO_voidSetPinValueAtomicAccess(LED5_PORT, LED5_Pin, OUTPUT_RESET);
    GPIO_voidSetPinValueAtomicAccess(LED6_PORT, LED6_Pin, OUTPUT_RESET);
    GPIO_voidSetPinValueAtomicAccess(LED7_PORT, LED7_Pin, OUTPUT_RESET);
}
void LED_voidSetMode(u8 Copyu8_LedPort, u8 Copyu8_LedPin, u8 Copyu8_LedSet)
{
    switch (Copyu8_LedSet)
    {
    case LED_ON:
        GPIO_voidSetPinValueAtomicAccess(Copyu8_LedPort, Copyu8_LedPin, OUTPUT_SET);
        break;
    case LED_OFF:
        GPIO_voidSetPinValueAtomicAccess(Copyu8_LedPort, Copyu8_LedPin, OUTPUT_RESET);
        break;

    default:

        break;
    }
}
void LED_voidBlinkNTimes(u8 Copyu8_LedPort, u8 Copyu8_LedPin, u8 Copyu8_NTimes, u32 Copyu8_Delayus)
{
    GPIO_voidSetPinValueAtomicAccess(Copyu8_LedPort, Copyu8_LedPin, OUTPUT_RESET);
    for (u8 i = 0; i < Copyu8_NTimes; i++)
    {
        GPIO_voidSetPinValueAtomicAccess(Copyu8_LedPort, Copyu8_LedPin, OUTPUT_SET);
        STK_voidDelay_us(Copyu8_Delayus);
        GPIO_voidSetPinValueAtomicAccess(Copyu8_LedPort, Copyu8_LedPin, OUTPUT_RESET);
        STK_voidDelay_us(Copyu8_Delayus);
    }
}