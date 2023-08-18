#include "std_types.h"
#include "Bit_Math.h"


#include "GPIO_Private.h"

#include "GPIO_Interface.h"

#include "GPIO_Config.h"

/**/
void GPIO_voidSetPinMode(volatile GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8PinMode)
{
    // ip validation
    if (!((GPIOx == GPIOA) || (GPIOx == GPIOB) || (GPIOx == GPIOC)) || (Copy_u8PinID > Pin15) || (Copy_u8PinMode > ANALOG))
    {
        return;
    }

    switch (Copy_u8PinMode)
    {
    case INPUT:
        CLEAR_BIT(GPIOx->MODER, Copy_u8PinID * 2);
        CLEAR_BIT(GPIOx->MODER, ((Copy_u8PinID * 2) + 1));
        break;
    case OUTPUT:
        SET_BIT(GPIOx->MODER, Copy_u8PinID * 2);
        CLEAR_BIT(GPIOx->MODER, ((Copy_u8PinID * 2) + 1));
        break;
    case AF:
        CLEAR_BIT(GPIOx->MODER, Copy_u8PinID * 2);
        SET_BIT(GPIOx->MODER, ((Copy_u8PinID * 2) + 1));
        break;
    case ANALOG:
        SET_BIT(GPIOx->MODER, Copy_u8PinID * 2);
        SET_BIT(GPIOx->MODER, ((Copy_u8PinID * 2) + 1));
        break;
    }
}

void GPIO_voidSetOutPutPinType(volatile GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8PinMode)
{
    if (!((GPIOx == GPIOA) || (GPIOx == GPIOB) || (GPIOx == GPIOC)) || (Copy_u8PinID > Pin15) || (Copy_u8PinMode > OUTPUT_OD))
    {
        return;
    }

    switch (Copy_u8PinMode)
    {
    case OUTPUT_PP:
        CLEAR_BIT(GPIOx->OTYPER, Copy_u8PinID);
        break;
    case OUTPUT_OD:
        SET_BIT(GPIOx->OTYPER, Copy_u8PinID);
        break;
    }
}
void GPIO_voidSetPinSpeed(volatile GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8PinSpeed)
{
    // ip validation
    if (!((GPIOx == GPIOA) || (GPIOx == GPIOB) || (GPIOx == GPIOC)) || (Copy_u8PinID > Pin15) || (Copy_u8PinSpeed > HS))
    {
        return;
    }

    switch (Copy_u8PinSpeed)
    {
    case LS:
        CLEAR_BIT(GPIOx->OSPEEDR, Copy_u8PinID * 2);
        CLEAR_BIT(GPIOx->OSPEEDR, ((Copy_u8PinID * 2) + 1));
        break;
    case MS:
        SET_BIT(GPIOx->OSPEEDR, Copy_u8PinID * 2);
        CLEAR_BIT(GPIOx->OSPEEDR, ((Copy_u8PinID * 2) + 1));
        break;
    case HS:
        CLEAR_BIT(GPIOx->OSPEEDR, Copy_u8PinID * 2);
        SET_BIT(GPIOx->OSPEEDR, ((Copy_u8PinID * 2) + 1));
        break;
    }
}

void GPIO_voidSetPuPdConfig(volatile GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8PUPDType)
{
    // ip validation
    if (!((GPIOx == GPIOA) || (GPIOx == GPIOB) || (GPIOx == GPIOC)) || (Copy_u8PinID > Pin15) || (Copy_u8PUPDType > INPUT_PULL_DOWN))
    {
        return;
    }

    switch (Copy_u8PUPDType)
    {
    case INPUT_FLOAT:
        CLEAR_BIT(GPIOx->PUPDR, Copy_u8PinID * 2);
        CLEAR_BIT(GPIOx->PUPDR, ((Copy_u8PinID * 2) + 1));
        break;
    case INPUT_PULL_UP:
        SET_BIT(GPIOx->PUPDR, Copy_u8PinID * 2);
        CLEAR_BIT(GPIOx->PUPDR, ((Copy_u8PinID * 2) + 1));
        break;
    case INPUT_PULL_DOWN:
        CLEAR_BIT(GPIOx->PUPDR, Copy_u8PinID * 2);
        SET_BIT(GPIOx->PUPDR, ((Copy_u8PinID * 2) + 1));
        break;
    }
}

void GPIO_voidSetPinValue(volatile GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8Value)
{
    if (!((GPIOx == GPIOA) || (GPIOx == GPIOB) || (GPIOx == GPIOC)) || (Copy_u8PinID > Pin15) || (Copy_u8Value > OUTPUT_HIGH))
    {
        return;
    }

    switch (Copy_u8Value)
    {
    case OUTPUT_LOW:
        CLEAR_BIT(GPIOx->ODR, Copy_u8PinID);
        break;
    case OUTPUT_HIGH:
        SET_BIT(GPIOx->ODR, Copy_u8PinID);
        break;
    }
}

void GPIO_voidToggleOutputPin(volatile GPIO_t *GPIOx, u8 Copy_u8PinID)
{
    TOGGLE_BIT(GPIOx->ODR,Copy_u8PinID);
}

void GPIO_voidSetPinValueAtomicAccess(volatile GPIO_t *GPIOx, u8 Copy_u8PinID, u8 Copy_u8SetRstType)
{
    if (!((GPIOx == GPIOA) || (GPIOx == GPIOB) || (GPIOx == GPIOC)) || (Copy_u8PinID > Pin15) || (Copy_u8SetRstType > OUTPUT_RESET))
    {
        return;
    }

    switch (Copy_u8SetRstType)
    {
    case OUTPUT_SET:
        GPIOx->BSRRL = 1 << Copy_u8PinID;
        break;
    case OUTPUT_RESET:
        GPIOx->BSRRH = 1 << Copy_u8PinID;
        break;
    }
}

void GPIO_voidSetPortValue(volatile GPIO_t *GPIOx, u32 Copy_u32Value)
{
    if (!((GPIOx == GPIOA) || (GPIOx == GPIOB) || (GPIOx == GPIOC)))
    {
        return;
    }
    GPIOx->ODR = Copy_u32Value;
}
u8 GPIO_u8GetPinValue(volatile GPIO_t *GPIOx, u8 Copy_u8PinID)
{
    if (!((GPIOx == GPIOA) || (GPIOx == GPIOB) || (GPIOx == GPIOC)) || (Copy_u8PinID > Pin15))
    {
        return (ERROR_VAL);
    }
    return (GET_BIT(GPIOx->IDR, Copy_u8PinID));
}
