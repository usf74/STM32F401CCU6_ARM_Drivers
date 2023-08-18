#ifndef __STK_PRIVATE_H__
#define __STK_PRIVATE_H__

#define STK_CTRL        *((volatile u32 *)0xE000E010)
#define STK_LOAD        *((volatile u32 *)0xE000E014)
#define STK_VAL         *((volatile u32 *)0xE000E018)
#define STK_CALIB       *((volatile u32 *)0xE000E01C)

#define SINGLE 0
#define REOCURRING 1

#define AHB_CLK 0
#define AHB_CLK_DIV_8 1

#endif // __STK_PRIVATE_H__