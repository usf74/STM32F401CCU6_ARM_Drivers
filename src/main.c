

#include "Bit_Math.h"
#include "std_types.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"

#include "S7_Interface.h"
#include "Buzzer_Interface.h"


int main()
{

    RCC_VoidInitSysClk();
    RCC_voidEnablePerClk(AHB1, 0);
    RCC_voidEnablePerClk(AHB1, 1);
    // Initialize pins
    /* for (u8 pin = Pin0; pin <= Pin7; pin++)
     {
         GPIO_voidSetPinMode(GPIOA, pin, OUTPUT);
         GPIO_voidSetOutPutPinType(GPIOA, pin, OUTPUT_PP);
         GPIO_voidSetPinSpeed(GPIOA, pin, LS);
         GPIO_voidSetPinValueAtomicAccess(GPIOA, pin, OUTPUT_RESET);
     }*/

    S7_voidInit();
    u8 Numba = 0;
    Buzzer_voidInit();
    Buzzer_voidBeepNTimes(3,1000000);

    //---------------------------------------------super loop----------------------------------------------------------------
    while (1)
    {
        for (u8 i = 0; i <= 99; i++, Numba++)
        {
            S7_voidDisplayInt(Numba);
            STK_voidDelay_us(500000);
        }
    }

    return 1;
}
