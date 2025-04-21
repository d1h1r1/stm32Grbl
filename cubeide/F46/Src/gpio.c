/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, SPI_SEL2_Pin|SPI_SEL3_Pin|I2C_OE_Pin|SPI_SEL0_Pin
                          |SPI_SEL1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DIR_X_Pin|DIR_Y_Pin|DIR_Z_Pin|DIR_A_Pin
                          |DIR_B_Pin|DIR_C_Pin|STEP_ENABLE_Pin|STEP_X_Pin
                          |STEP_Y_Pin|STEP_Z_Pin|STEP_A_Pin|STEP_B_Pin
                          |STEP_C_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, AUX_5_Pin|AUX_6_Pin|AUX_7_Pin|AUX_8_Pin
                          |AUX_1_Pin|AUX_2_Pin|AUX_3_Pin|AUX_4_Pin
                          |SPIN_DIR_Pin|SPIN_EN_Pin|COOL_MIST_Pin|COOL_FLOOD_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : SPI_SEL2_Pin SPI_SEL3_Pin SPI_SEL0_Pin SPI_SEL1_Pin */
  GPIO_InitStruct.Pin = SPI_SEL2_Pin|SPI_SEL3_Pin|SPI_SEL0_Pin|SPI_SEL1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : I2C_OE_Pin */
  GPIO_InitStruct.Pin = I2C_OE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(I2C_OE_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : DIR_X_Pin DIR_Y_Pin DIR_Z_Pin DIR_A_Pin
                           DIR_B_Pin DIR_C_Pin STEP_ENABLE_Pin STEP_X_Pin
                           STEP_Y_Pin STEP_Z_Pin STEP_A_Pin STEP_B_Pin
                           STEP_C_Pin */
  GPIO_InitStruct.Pin = DIR_X_Pin|DIR_Y_Pin|DIR_Z_Pin|DIR_A_Pin
                          |DIR_B_Pin|DIR_C_Pin|STEP_ENABLE_Pin|STEP_X_Pin
                          |STEP_Y_Pin|STEP_Z_Pin|STEP_A_Pin|STEP_B_Pin
                          |STEP_C_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : CON_FEED_HOLD_Pin CON_CYCLE_START_Pin CON_RESET_Pin INT_LIMITS_Pin
                           CON_SAFETY_DOOR_Pin */
  GPIO_InitStruct.Pin = CON_FEED_HOLD_Pin|CON_CYCLE_START_Pin|CON_RESET_Pin|INT_LIMITS_Pin
                          |CON_SAFETY_DOOR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : AUX_5_Pin AUX_6_Pin AUX_7_Pin AUX_8_Pin
                           AUX_1_Pin AUX_2_Pin AUX_3_Pin AUX_4_Pin
                           SPIN_DIR_Pin SPIN_EN_Pin COOL_MIST_Pin COOL_FLOOD_Pin */
  GPIO_InitStruct.Pin = AUX_5_Pin|AUX_6_Pin|AUX_7_Pin|AUX_8_Pin
                          |AUX_1_Pin|AUX_2_Pin|AUX_3_Pin|AUX_4_Pin
                          |SPIN_DIR_Pin|SPIN_EN_Pin|COOL_MIST_Pin|COOL_FLOOD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PROBE_Pin */
  GPIO_InitStruct.Pin = PROBE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(PROBE_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
