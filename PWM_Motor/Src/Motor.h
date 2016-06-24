#ifndef MOTOR_H_
#define MOTOR_H_
#include "stm32f4xx_hal.h"

#define motor1 htim4
extern TIM_HandleTypeDef htim4;

//void MX_GPIO_Init(void);
void MX_TIM4_Init(TIM_HandleTypeDef *htim4);
void init_motor(void);
void motor_test(TIM_HandleTypeDef *htim4);
void motor_forward(void);
void motor_reverse(void);
void motor_stop(void);
void motor_brake(void);
void motor_duty(uint32_t duty_cycle,TIM_HandleTypeDef *htim4);




#endif
