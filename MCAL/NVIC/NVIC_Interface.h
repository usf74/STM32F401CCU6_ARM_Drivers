#ifndef __NVIC_INTERFACE_H__
#define __NVIC_INTERFACE_H__


void NVIC_voidEnableIRQ(u8 IRQn);
void NVIC_voidDisableIRQ(u8 IRQn);
void NVIC_voidSetPendingIRQ(u8 IRQn);
void NVIC_voidClearPendingIRQ(u8 IRQn);
u8 NVIC_voidGetPendingIRQ(u8 IRQn);
void NVIC_voidSetPriority(u8 IRQn, u8 priority);
u8 NVIC_voidGetPriority(u8 IRQn);

#endif // __NVIC_INTERFACE_H__