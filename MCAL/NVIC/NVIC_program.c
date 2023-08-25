

#include "std_types.h"
#include "Bit_Math.h"

#include "NVIC_Private.h"
#include "NVIC_Interface.h"
#include "NVIC_Config.h"

void NVIC_voidEnableIRQ(u8 IRQn)
{
    NVIC->ISER[IRQn / 32] = 1 << (IRQn % 32);
}
void NVIC_voidDisableIRQ(u8 IRQn)
{
    NVIC->ICER[IRQn / 32] = 1 << (IRQn % 32);
}

void NVIC_voidSetPendingIRQ(u8 IRQn)
{
    NVIC->ISPR[IRQn / 32] = 1 << (IRQn % 32);
}
void NVIC_voidClearPendingIRQ(u8 IRQn)
{
    NVIC->ICPR[IRQn / 32] = 1 << (IRQn % 32);
}

u8 NVIC_voidGetPendingIRQ(u8 IRQn)
{
    return (GET_BIT(NVIC->ISPR[IRQn / 32], IRQn % 32));
}

void NVIC_voidSetPriority(u8 IRQn, u8 priority)
{
    NVIC->IPR[IRQn / 4] |= priority << (IRQn % 4);
}
