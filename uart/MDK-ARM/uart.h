#ifndef UART_H_
#define UART_H_
#include "stm32f4xx_hal.h"
#define uart3_debug 0
#define uart2_debug 1
#define jlink_debug 0

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
 

	
void MX_USART3_UART_Init(void);
void MX_USART2_UART_Init(void);	

#endif
