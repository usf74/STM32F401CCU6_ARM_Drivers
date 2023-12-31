#ifndef __RCC_CONF_H__
#define __RCC_CONF_H__

/***********************************/
/***********************************/
/***********************************/
/***********************************/
/***********************************/
/***********************************/
/***********************************/
/***********************************/
/***********************************/

#define SYS_CLK_SRC PLL
#define BYPASS_MODE NOT_BYPASSED

#define PLL_SOURCE HSE
#define PLLP 4   // 2 or 4 or 6 or 8
#define PLLM 25 //     2<= PLLM <= 63
#define PLLN 336 //     192<= PLLN <= 432

#endif // __RCC_CONF_H__
