#ifndef MOTOR_H_
#define MOTOR_H_
#include "stm32f4xx_hal.h"

//void MX_GPIO_Init(void);
void MX_TIM4_Init(TIM_HandleTypeDef *htim4);
void init_motor(void);
void motor_test(TIM_HandleTypeDef *htim4);
extern TIM_HandleTypeDef htim4;

#define motor1 htim4


#endif
