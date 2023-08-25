
#include "std_types.h"
#include "Bit_Math.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"

#include "LED_Private.h"
#include "LED_Config.h"
#include "LED_Interface.h"

void LED_voidInit(volatile GPIO_t * Copyu8_LedPort, u8 Copyu8_LedPin)
{
    GPIO_voidSetPinMode(Copyu8_LedPort, Copyu8_LedPin, OUTPUT);
    GPIO_voidSetOutPutPinType(Copyu8_LedPort, Copyu8_LedPin, OUTPUT_PP);
    GPIO_voidSetPinSpeed(Copyu8_LedPort, Copyu8_LedPin, LS);
    GPIO_voidSetPinValueAtomicAccess(Copyu8_LedPort, Copyu8_LedPin, OUTPUT_RESET);
}
void LED_voidSetMode(volatile GPIO_t * Copyu8_LedPort, u8 Copyu8_LedPin, u8 Copyu8_LedSet)
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
void LED_voidBlinkNTimes(volatile GPIO_t * Copyu8_LedPort, u8 Copyu8_LedPin, u8 Copyu8_NTimes, u32 Copyu8_Delayus)
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