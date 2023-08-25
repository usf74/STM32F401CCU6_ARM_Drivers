#ifndef __BUZZER_INTERFACE_H__
#define __BUZZER_INTERFACE_H__

#define BUZZER_voidON() GPIO_voidSetPinValueAtomicAccess(BUZZER_PORT, BUZZER_PIN, OUTPUT_SET)
#define BUZZER_voidOFF() GPIO_voidSetPinValueAtomicAccess(BUZZER_PORT, BUZZER_PIN, OUTPUT_RESET)
#define Buzzer_voidToggle() GPIO_voidToggleOutputPin(BUZZER_PORT, BUZZER_PIN)


void Buzzer_voidInit();
void Buzzer_voidSetMode(u8 Copy_u8BuzzerSet);
void Buzzer_voidBeepNTimes(u8 Copy_u8NTimes, u32 Copy_u8Delayus);





#endif // __BUZZER_INTERFACE_H__