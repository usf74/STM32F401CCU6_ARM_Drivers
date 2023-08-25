
#include "std_types.h"
#include "Bit_Math.h"
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"

void RCC_VoidInitSysClk()
{
    SET_BIT(RCC_CFGR,7);    //AHB1 PRESCALE to 2
#if SYS_CLK_SRC == HSI
    SET_BIT(RCC_CR, HSION);

    CLEAR_BIT(RCC_CFGR, SW0);
    CLEAR_BIT(RCC_CFGR, SW1);

#elif SYS_CLK_SRC == HSE
    SET_BIT(RCC_CR, HSEON);     //Turn on
    while (!GET_BIT(RCC_CR, 17));    //Wait ready

#if BYPASS_MODE == NOTPYBASSED
    CLEAR_BIT(RCC_CR, 18);
#elif BYPASS_MODE == PYBASSED
    SET_BIT(RCC_CR, 18);
#endif
    //Switch source
    SET_BIT(RCC_CFGR, SW0);
    CLEAR_BIT(RCC_CFGR, SW1);


#elif SYS_CLK_SRC == PLL

#if PLL_SOURCE == HSI
    CLEAR_BIT(RCC_PLLCFGR, PLLSRC);
#elif PLL_SOURCE == HSE
    SET_BIT(RCC_CR, HSEON);
    while (!GET_BIT(RCC_CR, 17));    //Wait ready
    SET_BIT(RCC_PLLCFGR, PLLSRC);
#if BYPASS_MODE == NOTPYBASSED
    CLEAR_BIT(RCC_CR, 18);
#elif BYPASS_MODE == PYBASSED
    SET_BIT(RCC_CR, 18);
#endif
#else
#error "Invalid PLL_CLK_SRC Configuration"
#endif

#if (((PLLP == 2) || (PLLP == 4) || (PLLP == 6) || (PLLP == 8)) && ((PLLN <= 432) || (PLLN >= 192)) && ((PLLM <= 63) || (PLLM >= 2)))   // i/p validation

    RCC_PLLCFGR = (RCC_PLLCFGR & 0xFFFC8000) | ((PLLP / 2 - 1) << 16) | (PLLN << 6) | PLLM;        /* ?????*/

#else
#error "Invalid PLL_CLK_SRC Symbol boundary"
#endif
    SET_BIT(RCC_CR, PLLON);
    while (!GET_BIT(RCC_CR,25));
    CLEAR_BIT(RCC_CFGR, SW0);
    SET_BIT(RCC_CFGR, SW1);

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
