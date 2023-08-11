#ifndef __GPIO_PRIVATE_H__
#define __GPIO_PRIVATE_H__

typedef struct
{
    volatile u32 MODER;   // Mode register
    volatile u16 OTYPER;  // Output type register
    volatile u16 rev0;    // Padding two bytes
    volatile u32 OSPEEDR; // Output speed register
    volatile u32 PUPDR;   // Pull-up/pull-down register
    volatile u16 IDR;     // Input data register
    u16 reservedl;        // Padding two bytes
    volatile u16 ODR;     // Output data register
    u16 reserved2;        // Padding two bytes
    volatile u16 BSRRL;   // Bit set/reset register(low)
    volatile u16 BSRRH;   // Bit set/reset register(high)
    volatile u32 LCKR;    // Configuration lock register
    volatile u32 AFR[2];  // Alternate function registers
    // volatile u32 BRR;     // Bit reset register
    // volatile u32 ASCR;    // Analog switch control register
}GPIO_t;




#endif // __GPIO_PRIVATE_H__