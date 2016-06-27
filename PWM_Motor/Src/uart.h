#ifndef UART_H_
#define UART_H_
#include "stm32f4xx_hal.h"
#define uart3_debug 1
#define uart2_debug 1
#define jlink_debug 1

extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart2;


#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
 
#if jlink_debug	
#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))

#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          0x01000000

struct __FILE { int handle; /* Add whatever needed */ };
extern FILE __stdout;
extern FILE __stdin;

#endif

void MX_USART3_UART_Init(void);
void MX_USART2_UART_Init(void);	




#endif
