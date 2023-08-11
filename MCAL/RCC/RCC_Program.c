
#include "../../LIB/std_types.h"
#include "../../LIB/Bit_Math.h"
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"

void RCC_VoidInitSysClk()
{
#if SYS_CLK_SRC == HSI
    SET_BIT(RCC_CR, HSION);

    CLEAR_BIT(RCC_CFGR, SW0);
    CLEAR_BIT(RCC_CFGR, SW1);

#elif SYS_CLK_SRC == HSE
    SET_BIT(RCC_CR, HSEON);

    SET_BIT(RCC_CFGR, SW0);
    CLEAR_BIT(RCC_CFGR, SW1);
    #if BYPASS_MODE == NOTPYBASSED
        CLR_BIT(RCC_CR, 18);
    #elif BYPASS_MODE == PYBASSED
        SET_BIT(RCC_CR, 18);
    #endif
#elif SYS_CLK_SRC == PLL
    /*To be implemented*/

#else
#error "Invalid SYS_CLK_SRC Configuration"

#endif
}

void RCC_voidEnablePerClk(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if ((Copy_u8BusId > APB2) || (Copy_u8PerId > 31))
    {
        return; /// do nothing
    }

    switch (Copy_u8BusId)
    {
    case AHB1:
        SET_BIT(RCC_AHB1ENR, Copy_u8PerId);
        break;

    case AHB2:
        if (Copy_u8PerId == 7)
        {
            SET_BIT(RCC_AHB2ENR, Copy_u8PerId);
        }
        break;
    case APB1:
        SET_BIT(RCC_APB1ENR, Copy_u8PerId);
        break;

    case APB2:
        SET_BIT(RCC_APB2ENR, Copy_u8PerId);
        break;
    }
}

void RCC_voidDisablePerClk(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if ((Copy_u8BusId > APB2) || (Copy_u8PerId > 31))
    {
        return; /// do nothing
    }

    switch (Copy_u8BusId)
    {
    case AHB1:
        CLEAR_BIT(RCC_AHB1ENR, Copy_u8PerId);
        break;

    case AHB2:
        if (Copy_u8PerId == 7)
        {
            CLEAR_BIT(RCC_AHB2ENR, Copy_u8PerId);
        }
        break;
    case APB1:
        CLEAR_BIT(RCC_APB1ENR, Copy_u8PerId);
        break;

    case APB2:
        CLEAR_BIT(RCC_APB2ENR, Copy_u8PerId);
        break;
    }
}