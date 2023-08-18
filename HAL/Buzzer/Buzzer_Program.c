
#include "std_types.h"
#include "Bit_Math.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"

#include "Buzzer_Private.h"
#include "Buzzer_Interface.h"
#include "Buzzer_Config.h"

void Buzzer_voidInit()
{
    GPIO_voidSetPinMode(BUZZER_PORT, BUZZER_PIN, OUTPUT);
    GPIO_voidSetOutPutPinType(BUZZER_PORT, BUZZER_PIN, OUTPUT_PP);
    GPIO_voidSetPinSpeed(BUZZER_PORT, BUZZER_PIN, LS);
    GPIO_voidSetPinValueAtomicAccess(BUZZER_PORT, BUZZER_PIN, OUTPUT_RESET);
}

void Buzzer_voidSetMode(u8 Copy_u8BuzzerSet)
{
    switch (Copy_u8BuzzerSet)
    {
    case BUZZER_ON:
        GPIO_voidSetPinValueAtomicAccess(BUZZER_PORT, BUZZER_PIN, OUTPUT_SET);
        break;
    case BUZZER_OFF:
        GPIO_voidSetPinValueAtomicAccess(BUZZER_PORT, BUZZER_PIN, OUTPUT_RESET);
        break;

    default:

        break;
    }
}

void Buzzer_voidBeepNTimes(u8 Copy_u8NTimes, u32 Copy_u8Delayus)
{
    GPIO_voidSetPinValueAtomicAccess(BUZZER_PORT, BUZZER_PIN, OUTPUT_RESET);
    for (u8 i = 0; i < Copy_u8NTimes; i++)
    {
        GPIO_voidSetPinValueAtomicAccess(BUZZER_PORT, BUZZER_PIN, OUTPUT_SET);
        STK_voidDelay_us(Copy_u8Delayus);
        GPIO_voidSetPinValueAtomicAccess(BUZZER_PORT, BUZZER_PIN, OUTPUT_RESET);
        STK_voidDelay_us(Copy_u8Delayus);
    }
}
