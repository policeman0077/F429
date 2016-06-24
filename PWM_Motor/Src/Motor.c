#include "Motor.h"
#include "GPIO.h"
TIM_HandleTypeDef htim4;

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

void init_motor(void)
{
  
	//TIM_HandleTypeDef htim4;
	
	MX_GPIO_Init();
  MX_TIM4_Init(&htim4);
	HAL_TIM_Base_Start(&htim4);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	
	
}	

/* TIM4 init function */
void MX_TIM4_Init(TIM_HandleTypeDef *htim4)
{

  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim4->Instance = TIM4;
  htim4->Init.Prescaler = 0;
  htim4->Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4->Init.Period = 3750-1;
  htim4->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  HAL_TIM_PWM_Init(htim4);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  HAL_TIMEx_MasterConfigSynchronization(htim4, &sMasterConfig);

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  HAL_TIM_PWM_ConfigChannel(htim4, &sConfigOC, TIM_CHANNEL_1);

  sConfigOC.Pulse = 1875-1;
  HAL_TIM_PWM_ConfigChannel(htim4, &sConfigOC, TIM_CHANNEL_2);

  HAL_TIM_MspPostInit(htim4);

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
//void MX_GPIO_Init(void)
//{

//  /* GPIO Ports Clock Enable */
//  __HAL_RCC_GPIOH_CLK_ENABLE();
//  __HAL_RCC_GPIOD_CLK_ENABLE();
//  __HAL_RCC_GPIOB_CLK_ENABLE();

//}
void motor_test(TIM_HandleTypeDef *htim4)
{
      int pwm =0;
           for(pwm=0;pwm<=3749;pwm++)
		 {
		 
		  __HAL_TIM_SetCompare(htim4,TIM_CHANNEL_2,pwm);
		  __HAL_TIM_SetCompare(htim4,TIM_CHANNEL_1,pwm/2);	 
		  HAL_Delay(1);   
		 }
		 
		 for(pwm=3749;pwm>=0;pwm--)
		 {
		 
		  __HAL_TIM_SetCompare(htim4,TIM_CHANNEL_2,pwm);
		  __HAL_TIM_SetCompare(htim4,TIM_CHANNEL_1,pwm/2); 
		  HAL_Delay(1);   
		 }

}

