#ifndef __RCC_INTERFACE_H__
#define __RCC_INTERFACE_H__


void RCC_VoidInitSysClk();
void RCC_voidEnablePerClk(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisablePerClk(u8 Copy_u8BusId, u8 Copy_u8PerId);

//Here in interface since they are input params
#define AHB1 0
#define AHB2 1
#define APB1 2
#define APB2 3

#endif // __RCC_INTERFACE_H__