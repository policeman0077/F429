#ifndef MOTOR_H_
#define MOTOR_H_
#include "stm32f4xx_hal.h"

static void MX_GPIO_Init(void);
static void MX_TIM4_Init(TIM_HandleTypeDef htim4);
static void init_motor(TIM_HandleTypeDef htim4);



#endif
