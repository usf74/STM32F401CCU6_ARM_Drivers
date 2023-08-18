#ifndef __BUZZER_INTERFACE_H__
#define __BUZZER_INTERFACE_H__



void Buzzer_voidInit();
void Buzzer_voidSetMode(u8 Copy_u8BuzzerSet);

void Buzzer_voidBeepNTimes(u8 Copy_u8NTimes, u32 Copy_u8Delayus);
#define Buzzer_voidToggle() GPIO_voidToggleOutputPin(BUZZER_PORT, BUZZER_PIN)

#define BUZZER_ON 1
#define BUZZER_OFF 0

#endif // __BUZZER_INTERFACE_H__