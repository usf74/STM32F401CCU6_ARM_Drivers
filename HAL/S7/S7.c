
#include "std_types.h"
#include "Bit_Math.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"
#include "S7_Private.h"
#include "S7_Interface.h"
#include "S7_Config.h"

void S7_voidInit()
{
    // 7 segment 1 intialization
    // Setting pins to output
    GPIO_voidSetPinMode(S7_1_A_PORT, S7_1_A, OUTPUT);
    GPIO_voidSetPinMode(S7_1_B_PORT, S7_1_B, OUTPUT);
    GPIO_voidSetPinMode(S7_1_C_PORT, S7_1_C, OUTPUT);
    GPIO_voidSetPinMode(S7_1_D_PORT, S7_1_D, OUTPUT);
    GPIO_voidSetPinMode(S7_1_E_PORT, S7_1_E, OUTPUT);
    GPIO_voidSetPinMode(S7_1_F_PORT, S7_1_F, OUTPUT);
    GPIO_voidSetPinMode(S7_1_G_PORT, S7_1_G, OUTPUT);
    GPIO_voidSetPinMode(S7_1_DOT_PORT, S7_1_DOT, OUTPUT);
    // Setting to push pull mode
    GPIO_voidSetOutPutPinType(S7_1_A_PORT, S7_1_A, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(S7_1_B_PORT, S7_1_B, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(S7_1_C_PORT, S7_1_C, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(S7_1_D_PORT, S7_1_D, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(S7_1_E_PORT, S7_1_E, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(S7_1_F_PORT, S7_1_F, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(S7_1_G_PORT, S7_1_G, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(S7_1_DOT_PORT, S7_1_DOT, OUTPUT_PP);
    // Set speed to low
    GPIO_voidSetPinSpeed(S7_1_A_PORT, S7_1_A, LS);
    GPIO_voidSetPinSpeed(S7_1_B_PORT, S7_1_B, LS);
    GPIO_voidSetPinSpeed(S7_1_C_PORT, S7_1_C, LS);
    GPIO_voidSetPinSpeed(S7_1_D_PORT, S7_1_D, LS);
    GPIO_voidSetPinSpeed(S7_1_E_PORT, S7_1_E, LS);
    GPIO_voidSetPinSpeed(S7_1_F_PORT, S7_1_F, LS);
    GPIO_voidSetPinSpeed(S7_1_G_PORT, S7_1_G, LS);
    GPIO_voidSetPinSpeed(S7_1_DOT_PORT, S7_1_DOT, LS);
    // Set pins to high since common anode 7 segment
    GPIO_voidSetPinValueAtomicAccess(S7_1_A_PORT, S7_1_A, OUTPUT_SET);
    GPIO_voidSetPinValueAtomicAccess(S7_1_B_PORT, S7_1_B, OUTPUT_SET);
    GPIO_voidSetPinValueAtomicAccess(S7_1_C_PORT, S7_1_C, OUTPUT_SET);
    GPIO_voidSetPinValueAtomicAccess(S7_1_D_PORT, S7_1_D, OUTPUT_SET);
    GPIO_voidSetPinValueAtomicAccess(S7_1_E_PORT, S7_1_E, OUTPUT_SET);
    GPIO_voidSetPinValueAtomicAccess(S7_1_F_PORT, S7_1_F, OUTPUT_SET);
    GPIO_voidSetPinValueAtomicAccess(S7_1_G_PORT, S7_1_G, OUTPUT_SET);
    GPIO_voidSetPinValueAtomicAccess(S7_1_DOT_PORT, S7_1_DOT, OUTPUT_SET);

    // 7 segment 2 intialization
    // Setting pins to output
    GPIO_voidSetPinMode(S7_2_A_PORT, S7_2_A, OUTPUT);
    GPIO_voidSetPinMode(S7_2_B_PORT, S7_2_B, OUTPUT);
    GPIO_voidSetPinMode(S7_2_C_PORT, S7_2_C, OUTPUT);
    GPIO_voidSetPinMode(S7_2_D_PORT, S7_2_D, OUTPUT);
    GPIO_voidSetPinMode(S7_2_E_PORT, S7_2_E, OUTPUT);
    GPIO_voidSetPinMode(S7_2_F_PORT, S7_2_F, OUTPUT);
    GPIO_voidSetPinMode(S7_2_G_PORT, S7_2_G, OUTPUT);
    GPIO_voidSetPinMode(S7_2_DOT_PORT, S7_2_DOT, OUTPUT);
    // Setting to push pull mode
    GPIO_voidSetOutPutPinType(S7_2_A_PORT, S7_2_A, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(S7_2_B_PORT, S7_2_B, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(S7_2_C_PORT, S7_2_C, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(S7_2_D_PORT, S7_2_D, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(S7_2_E_PORT, S7_2_E, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(S7_2_F_PORT, S7_2_F, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(S7_2_G_PORT, S7_2_G, OUTPUT_PP);
    GPIO_voidSetOutPutPinType(S7_2_DOT_PORT, S7_2_DOT, OUTPUT_PP);
    // Set speed to low
    GPIO_voidSetPinSpeed(S7_2_A_PORT, S7_2_A, LS);
    GPIO_voidSetPinSpeed(S7_2_B_PORT, S7_2_B, LS);
    GPIO_voidSetPinSpeed(S7_2_C_PORT, S7_2_C, LS);
    GPIO_voidSetPinSpeed(S7_2_D_PORT, S7_2_D, LS);
    GPIO_voidSetPinSpeed(S7_2_E_PORT, S7_2_E, LS);
    GPIO_voidSetPinSpeed(S7_2_F_PORT, S7_2_F, LS);
    GPIO_voidSetPinSpeed(S7_2_G_PORT, S7_2_G, LS);
    GPIO_voidSetPinSpeed(S7_2_DOT_PORT, S7_2_DOT, LS);
    // Set pins to high since common anode 7 segment
    GPIO_voidSetPinValueAtomicAccess(S7_2_A_PORT, S7_2_A, OUTPUT_SET);
    GPIO_voidSetPinValueAtomicAccess(S7_2_B_PORT, S7_2_B, OUTPUT_SET);
    GPIO_voidSetPinValueAtomicAccess(S7_2_C_PORT, S7_2_C, OUTPUT_SET);
    GPIO_voidSetPinValueAtomicAccess(S7_2_D_PORT, S7_2_D, OUTPUT_SET);
    GPIO_voidSetPinValueAtomicAccess(S7_2_E_PORT, S7_2_E, OUTPUT_SET);
    GPIO_voidSetPinValueAtomicAccess(S7_2_F_PORT, S7_2_F, OUTPUT_SET);
    GPIO_voidSetPinValueAtomicAccess(S7_2_G_PORT, S7_2_G, OUTPUT_SET);
    GPIO_voidSetPinValueAtomicAccess(S7_2_DOT_PORT, S7_2_DOT, OUTPUT_SET);
}

void S7_voidDisplayInt(u8 Num)
{
    if (Num > 99)
    {
        return;
    }
    S7_voidResetDisplay();
    u8 Digits = Num % 10, Tens = Num / 10;

    GPIO_voidSetPinValue(S7_2_A_PORT, S7_2_A, GET_BIT(Numbers_Decode[Tens], 6));
    GPIO_voidSetPinValue(S7_2_B_PORT, S7_2_B, GET_BIT(Numbers_Decode[Tens], 5));
    GPIO_voidSetPinValue(S7_2_C_PORT, S7_2_C, GET_BIT(Numbers_Decode[Tens], 4));
    GPIO_voidSetPinValue(S7_2_D_PORT, S7_2_D, GET_BIT(Numbers_Decode[Tens], 3));
    GPIO_voidSetPinValue(S7_2_E_PORT, S7_2_E, GET_BIT(Numbers_Decode[Tens], 2));
    GPIO_voidSetPinValue(S7_2_F_PORT, S7_2_F, GET_BIT(Numbers_Decode[Tens], 1));
    GPIO_voidSetPinValue(S7_2_G_PORT, S7_2_G, GET_BIT(Numbers_Decode[Tens], 0));

    GPIO_voidSetPinValue(S7_1_A_PORT, S7_1_A, GET_BIT(Numbers_Decode[Digits], 6));
    GPIO_voidSetPinValue(S7_1_B_PORT, S7_1_B, GET_BIT(Numbers_Decode[Digits], 5));
    GPIO_voidSetPinValue(S7_1_C_PORT, S7_1_C, GET_BIT(Numbers_Decode[Digits], 4));
    GPIO_voidSetPinValue(S7_1_D_PORT, S7_1_D, GET_BIT(Numbers_Decode[Digits], 3));
    GPIO_voidSetPinValue(S7_1_E_PORT, S7_1_E, GET_BIT(Numbers_Decode[Digits], 2));
    GPIO_voidSetPinValue(S7_1_F_PORT, S7_1_F, GET_BIT(Numbers_Decode[Digits], 1));
    GPIO_voidSetPinValue(S7_1_G_PORT, S7_1_G, GET_BIT(Numbers_Decode[Digits], 0));
}

void S7_voidResetDisplay()
{
    GPIO_voidSetPinValue(S7_1_A_PORT, S7_1_A, S7_OFF);
    GPIO_voidSetPinValue(S7_1_B_PORT, S7_1_B, S7_OFF);
    GPIO_voidSetPinValue(S7_1_C_PORT, S7_1_C, S7_OFF);
    GPIO_voidSetPinValue(S7_1_D_PORT, S7_1_D, S7_OFF);
    GPIO_voidSetPinValue(S7_1_E_PORT, S7_1_E, S7_OFF);
    GPIO_voidSetPinValue(S7_1_F_PORT, S7_1_F, S7_OFF);
    GPIO_voidSetPinValue(S7_1_G_PORT, S7_1_G, S7_OFF);

    GPIO_voidSetPinValue(S7_2_A_PORT, S7_2_A, S7_OFF);
    GPIO_voidSetPinValue(S7_2_B_PORT, S7_2_B, S7_OFF);
    GPIO_voidSetPinValue(S7_2_C_PORT, S7_2_C, S7_OFF);
    GPIO_voidSetPinValue(S7_2_D_PORT, S7_2_D, S7_OFF);
    GPIO_voidSetPinValue(S7_2_E_PORT, S7_2_E, S7_OFF);
    GPIO_voidSetPinValue(S7_2_F_PORT, S7_2_F, S7_OFF);
    GPIO_voidSetPinValue(S7_2_G_PORT, S7_2_G, S7_OFF);

    GPIO_voidSetPinValue(S7_1_DOT_PORT, S7_1_DOT, S7_OFF);
    GPIO_voidSetPinValue(S7_2_DOT_PORT, S7_2_DOT, S7_OFF);
}
void S7_voidDisplayFloat(f32 Num)
{
    if (!(Num < 10))
    {
        return;
    }
    S7_voidDisplayInt(((u8)(Num * 10)));
    GPIO_voidSetPinValue(S7_2_DOT_PORT, S7_2_DOT, S7_ON);
}