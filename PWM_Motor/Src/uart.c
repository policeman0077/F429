#include "uart.h"

UART_HandleTypeDef huart3;
UART_HandleTypeDef huart2;
FILE __stdout;
FILE __stdin;

void MX_USART3_UART_Init(void)
{
  
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart3);

}
void MX_USART2_UART_Init(void)
{
  
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart2);

}


    
   int fputc(int ch, FILE *f) 
	{
				#if uart2_debug
	      HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 100);
	      #endif
		
		    #if uart3_debug
				HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, 100);
				#endif
		
		    #if jlink_debug
		    if (DEMCR & TRCENA) {
					while (ITM_Port32(0) == 0);
					ITM_Port8(0) = ch;
				}
				#endif
				
				return(ch);
   }  





