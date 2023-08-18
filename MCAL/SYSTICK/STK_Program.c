#include "std_types.h"
#include "Bit_Math.h"

#include "STK_Interface.h"
#include "STK_Private.h"
#include "STK_Config.h"

void (*Gfp)(void) = NULL; // Global function pointer
u8 Func_Flag = SINGLE;



void STK_voidInit()
{
    STK_CTRL = 0;

// CLock selection
#if STK_CLK == AHB_CLK

    SET_BIT(STK_CTRL, 2);

#endif
}

void STK_voidDelay_us(u32 Copy_u32us) // polled wait
{
    CLEAR_BIT(STK_CTRL, 1);
    STK_LOAD = Copy_u32us * CLK;
    SET_BIT(STK_CTRL, 0);
    while (!GET_BIT(STK_CTRL, 16))
    {
        // Nothing
    }
    CLEAR_BIT(STK_CTRL, 0);
    GET_BIT(STK_CTRL, 16); // Clear exception flag by reading
}

void STK_voidCounter_us_Single(u32 Copy_u32us, void (*Lfp)(void))
{
    Func_Flag = SINGLE;
    SET_BIT(STK_CTRL, 1);
    STK_LOAD = Copy_u32us * CLK;
    Gfp = Lfp;
    SET_BIT(STK_CTRL, 0);
}
void STK_voidCounter_us_Reoccuring(u32 Copy_u32us, void (*Lfp)(void))
{
    Func_Flag = REOCURRING;
    SET_BIT(STK_CTRL, 1);
    STK_LOAD = Copy_u32us * CLK;
    SET_BIT(STK_CTRL, 0);
    Gfp = Lfp;
}

u32 STK_u32GetElapsedTime(void)
{
    return ((STK_LOAD - STK_VAL) / CLK);
}
u32 STK_u32GetRemainingTime(void)
{
    return (STK_VAL / CLK);
}

void SysTick_Handler()
{
    if (Gfp != NULL)
    {
        Gfp();
    }
    GET_BIT(STK_CTRL, 16); // Clear exception flag by reading
    if (Func_Flag == SINGLE)
    {
        CLEAR_BIT(STK_CTRL, 0);
    }
}
