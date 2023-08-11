#ifndef __RCC_PRIVATE_H__
#define __RCC_PRIVATE_H__

/*struct RCC_TypedefStruct
{
    volatile u32 RCC_CR;         // RCC control register
    volatile u32 RCC_PLLCFGR;    // PLL configuartion register
    volatile u32 RCC_CFGR;       // Clock configuration register
    volatile u32 RCC_CIR;        // Clock interrupt register
    volatile u32 RCC_AHB1RSTR;   // AHB 1 peripheral reset register
    volatile u32 RCC_AHB2RSTR;   // AHB 2 peripheral reset register
    u32 reservedl;               // Padding four bytes
    u32 reserved2;               // Padding four bytes
    volatile u32 RCC_APB1RSTR;   // APB 1 peripheral reset register
    volatile u32 RCC_APB2RSTR;   // APB 2 peripheral reset register
    u32 reserved3;               // Padding four bytes
    u32 reserved4;               // Padding four bytes
    volatile u32 RCC_AHB1ENR;    // AHB 1 clock enable register
    volatile u32 RCC_AHB2ENR;    // AHB 2 clock enable register
    u32 reserved5;               // Padding four bytes
    u32 reserved6;               // Padding four bytes
    volatile u32 RCC_APB1ENR;    // APB 1 clock enable register
    volatile u32 RCC_APB2ENR;    // APB 2 clock enable register
    u32 reserved7;               // Padding four bytes
    u32 reserved8;               // Padding four bytes
    volatile u32 RCC_AHB1LPENR;  // AHB 1 peripheral clock enable in low power mode register
    volatile u32 RCC_AHB2LPENR;  // AHB 2 peripheral clock enable in low power mode register
    u32 reserved9;               // Padding four bytes
    u32 reserved10;              // Padding four bytes
    volatile u32 RCC_APB1LPENR;  // APB 1 peripheral clock enable in low power mode register
    volatile u32 RCC_APB2LPENR;  // APB 2 peripheral clock enable in low power mode register
    u32 reserved11;              // Padding four bytes
    u32 reserved12;              // Padding four bytes
    volatile u32 RCC_BDCR;       // Backup domain control register
    volatile u32 RCC_CSR;        // clock control & status register
    u32 reserved13;              // Padding four bytes
    u32 reserved14;              // Padding four bytes
    volatile u32 RCC_SSCGR;      // spread spectrum clock generation register
    volatile u32 RCC_PLLI2SCFGR; // PLLI2S configuration register
    u32 reserved15;              // Padding four bytes
    volatile u32 RCC_DCKCFGR;    // Dedicated Clocks Configuration Register
};

#define RCC ((RCC_TypedefStruct *)0x40023800)*/

/*RCC : AHB1, Base Address: 0x40023800*/
#define RCC_CR *((volatile u32 *)0x40023800)
#define RCC_PLLCFGR *((volatile u32 *)0x40023804)
#define RCC_CFGR *((volatile u32 *)0x40023808)
#define RCC_AHB1ENR *((volatile u32 *)0x40023830)
#define RCC_AHB2ENR *((volatile u32 *)0x40023834)
#define RCC_APB1ENR *((volatile u32 *)0x40023840)
#define RCC_APB2ENR *((volatile u32 *)0x40023844)

//

#define HSI 0
#define HSE 1
#define PLL 2

#define HSION 0
#define HSEON 16
#define SW0 0
#define SW1 1

#define NOT_BYPASSED 0
#define BYPASSED 1

#endif // __RCC_PRIVATE_H__