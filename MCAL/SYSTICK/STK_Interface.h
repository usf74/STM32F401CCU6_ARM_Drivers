#ifndef __STK_INTERFACE_H__
#define __STK_INTERFACE_H__

void STK_voidInit();

void STK_voidDelay_us(u32 Copy_u32us); //polled wait
void STK_voidCounter_us_Single(u32 Copy_u32us,void (*Lfp)(void)); //set timer then continue and wait interrupt once
void STK_voidCounter_us_Reoccuring(u32 Copy_u32us,void (*Lfp)(void)); //set timer then continue and wait interrupt uniform

u32  STK_u32GetElapsedTime(void);
u32  STK_u32GetRemainingTime(void);


#endif // __STK_INTERFACE_H__