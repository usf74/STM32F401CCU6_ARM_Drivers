#ifndef __LED_INTERFACE_H__
#define __LED_INTERFACE_H__

#include "LED_Config.h"

void LED_voidInit(volatile GPIO_t *, u8 Copyu8_LedPin);
void LED_voidSetMode(volatile GPIO_t *, u8 Copyu8_LedPin, u8 Copyu8_LedSet);
void LED_voidBlinkNTimes(volatile GPIO_t *, u8 Copyu8_LedPin, u8 Copyu8_NTimes, u32 Copyu8_Delayus);



#define LED_ON 1
#define LED_OFF 0


#endif // __LED_INTERFACE_H__