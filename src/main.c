

#include "Bit_Math.h"
#include "std_types.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"

#include "RCC_Private.h"

#define NORMAL_DELAY 500000 // 300ms

int main()
{

    RCC_VoidInitSysClk();
    RCC_voidEnablePerClk(AHB1, 0);

    // Initialize pins
    for (u8 PinI = 0; PinI <= Pin7; PinI++)
    {
        GPIO_voidSetPinMode(GPIOA, PinI, OUTPUT);
        GPIO_voidSetOutPutPinType(GPIOA, PinI, OUTPUT_PP);
        GPIO_voidSetPinSpeed(GPIOA, PinI, LS);
        GPIO_voidSetPinValueAtomicAccess(GPIOA, PinI, OUTPUT_RESET);
    }

    //---------------------------------------------super loop----------------------------------------------------------------//
    while (1)
    {
        GPIO_voidSetPinValue(GPIOA, Pin0, GET_BIT(RCC_CFGR, 2));
        GPIO_voidSetPinValue(GPIOA, Pin1, GET_BIT(RCC_CFGR, 3));
        // GPIO_voidSetPinValue(GPIOA, Pin2, GET_BIT(RCC_PLLCFGR, 11));
        // GPIO_voidSetPinValue(GPIOA, Pin3, GET_BIT(RCC_PLLCFGR, 6));
        // GPIO_voidSetPinValue(GPIOA, Pin4, GET_BIT(RCC_PLLCFGR,7));
        // GPIO_voidSetPinValue(GPIOA, Pin5, GET_BIT(RCC_PLLCFGR, 8));

        GPIO_voidSetPinValueAtomicAccess(GPIOA, Pin7, OUTPUT_SET);
        STK_voidDelay_us(NORMAL_DELAY);
        GPIO_voidSetPinValueAtomicAccess(GPIOA, Pin7, OUTPUT_RESET);
        STK_voidDelay_us(NORMAL_DELAY);
    }

    return 1;
}
