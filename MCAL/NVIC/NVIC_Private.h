#ifndef __NVIC_PRIVATE_H__
#define __NVIC_PRIVATE_H__


typedef struct
{
    u32 ISER[8];
    u32 ICER[8];
    u32 ISPR[8];
    u32 ICPR[8];
    u32 IABR[8];
    u32 IPR[8];
    u32 STIR[8];
    


}NVIC_t;

#define NVIC ((volatile NVIC_t *)0xE000E100)


#endif // __NVIC_PRIVATE_H__