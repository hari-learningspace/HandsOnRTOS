/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
typedef StaticSemaphore_t osStaticSemaphoreDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for GreenTask */
osThreadId_t GreenTaskHandle;
uint32_t GreenTaskBuffer[ 128 ];
osStaticThreadDef_t GreenTaskControlBlock;
const osThreadAttr_t GreenTask_attributes = {
  .name = "GreenTask",
  .stack_mem = &GreenTaskBuffer[0],
  .stack_size = sizeof(GreenTaskBuffer),
  .cb_mem = &GreenTaskControlBlock,
  .cb_size = sizeof(GreenTaskControlBlock),
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for BlueTask */
osThreadId_t BlueTaskHandle;
uint32_t BlueTaskBuffer[ 128 ];
osStaticThreadDef_t BlueTaskControlBlock;
const osThreadAttr_t BlueTask_attributes = {
  .name = "BlueTask",
  .stack_mem = &BlueTaskBuffer[0],
  .stack_size = sizeof(BlueTaskBuffer),
  .cb_mem = &BlueTaskControlBlock,
  .cb_size = sizeof(BlueTaskControlBlock),
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for semPtr */
osSemaphoreId_t semPtrHandle;
osStaticSemaphoreDef_t SemPControlBlock;
const osSemaphoreAttr_t semPtr_attributes = {
  .name = "semPtr",
  .cb_mem = &SemPControlBlock,
  .cb_size = sizeof(SemPControlBlock),
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void polledUartReceive(void * NotUsed){
	uint8_t nextbyte;
	while(1){
		while(!(USART2->SR & USART_SR_RXNE_Msk));
		nextbyte = USART2->DR;
		xQueueSend(uart2_BytesReceivedHandle,&nextbyte,0);
	}
}


void uartPrintOutTask(void *Notused){
	char nextByte;
	while(1){
		xQueueReceive(uart2_BytesReceivedHandle,&nextByte, 5000);
		SEGGER_SYSVIEW_PrintfHost("%c",nextByte);
	}
}
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void StartGreenTask(void *argument);
void StartBlueTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* creation of semPtr */
  semPtrHandle = osSemaphoreNew(1, 1, &semPtr_attributes);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of GreenTask */
  GreenTaskHandle = osThreadNew(StartGreenTask, NULL, &GreenTask_attributes);

  /* creation of BlueTask */
  BlueTaskHandle = osThreadNew(StartBlueTask, NULL, &BlueTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartGreenTask */
/**
* @brief Function implementing the GreenTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartGreenTask */
void StartGreenTask(void *argument)
{
  /* USER CODE BEGIN StartGreenTask */
  int8_t countv =0;
  /* Infinite loop */
  for(;;)
  {
	 if(countv++ >= 5){
		 countv = 0;
		 SEGGER_SYSVIEW_PrintfHost("Task A (green LED) gives semPtr");
		 osSemaphoreRelease(semPtrHandle);

	 }
	 HAL_GPIO_WritePin(GREENLED_GPIO_Port,GREENLED_Pin,SET);
	 vTaskDelay(100);
	 HAL_GPIO_WritePin(GREENLED_GPIO_Port,GREENLED_Pin,RESET);
	 vTaskDelay(100);
  }
  /* USER CODE END StartGreenTask */
}

/* USER CODE BEGIN Header_StartBlueTask */
/**
* @brief Function implementing the BlueTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartBlueTask */
void StartBlueTask(void *argument)
{
  /* USER CODE BEGIN StartBlueTask */
	SEGGER_SYSVIEW_PrintfHost("Blue Task waiting for Semaphore");
  int8_t i;
  /* Infinite loop */
  for(;;)
  {
      if(osSemaphoreAcquire(semPtrHandle,1000) == osOK){
    	  for(i=0; i <3 ; i++){

    		 HAL_GPIO_WritePin(BLUELED_GPIO_Port,BLUELED_Pin,SET);
			 vTaskDelay(50);
			 HAL_GPIO_WritePin(BLUELED_GPIO_Port,BLUELED_Pin,RESET);
			 vTaskDelay(50);

    	  }
      }else {
		  //Timeout due to waiting for semaphore
    	  SEGGER_SYSVIEW_PrintfHost("Timeout Due to No Semaphore");
	  }
  }
  /* USER CODE END StartBlueTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
