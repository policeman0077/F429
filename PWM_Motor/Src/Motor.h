#ifndef MOTOR_H_
#define MOTOR_H_
#include "stm32f4xx_hal.h"

void MX_GPIO_Init(void);
void MX_TIM4_Init(TIM_HandleTypeDef *htim4);
void init_motor(TIM_HandleTypeDef *htim4);
void motor_test(TIM_HandleTypeDef *htim4);



#endif
