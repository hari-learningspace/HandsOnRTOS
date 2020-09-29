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
#include "queue.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
typedef StaticQueue_t osStaticMessageQDef_t;
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
/* Definitions for mypolledUartRec */
osThreadId_t mypolledUartRecHandle;
uint32_t polledUartReceiBuffer[ 128 ];
osStaticThreadDef_t polledUartReceiControlBlock;
const osThreadAttr_t mypolledUartRec_attributes = {
  .name = "mypolledUartRec",
  .stack_mem = &polledUartReceiBuffer[0],
  .stack_size = sizeof(polledUartReceiBuffer),
  .cb_mem = &polledUartReceiControlBlock,
  .cb_size = sizeof(polledUartReceiControlBlock),
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for myTask03 */
osThreadId_t myTask03Handle;
uint32_t myTask03Buffer[ 128 ];
osStaticThreadDef_t myTask03ControlBlock;
const osThreadAttr_t myTask03_attributes = {
  .name = "myTask03",
  .stack_mem = &myTask03Buffer[0],
  .stack_size = sizeof(myTask03Buffer),
  .cb_mem = &myTask03ControlBlock,
  .cb_size = sizeof(myTask03ControlBlock),
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for uart2_BytesReceived */
osMessageQueueId_t uart2_BytesReceivedHandle;
uint8_t uart2_BytesReceivedBuffer[ 8 * sizeof( uint16_t ) ];
osStaticMessageQDef_t uart2_BytesReceivedControlBlock;
const osMessageQueueAttr_t uart2_BytesReceived_attributes = {
  .name = "uart2_BytesReceived",
  .cb_mem = &uart2_BytesReceivedControlBlock,
  .cb_size = sizeof(uart2_BytesReceivedControlBlock),
  .mq_mem = &uart2_BytesReceivedBuffer,
  .mq_size = sizeof(uart2_BytesReceivedBuffer)
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void polledUartReceive(void *argument);
void uartPrintOutTask(void *argument);

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

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of uart2_BytesReceived */
  uart2_BytesReceivedHandle = osMessageQueueNew (8, sizeof(uint16_t), &uart2_BytesReceived_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of mypolledUartRec */
  mypolledUartRecHandle = osThreadNew(polledUartReceive, NULL, &mypolledUartRec_attributes);

  /* creation of myTask03 */
  myTask03Handle = osThreadNew(uartPrintOutTask, NULL, &myTask03_attributes);

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

/* USER CODE BEGIN Header_polledUartReceive */
/**
* @brief Function implementing the mypolledUartRec thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_polledUartReceive */
void polledUartReceive(void *argument)
{
  /* USER CODE BEGIN polledUartReceive */
	uint8_t nextByte;
  /* Infinite loop */
  for(;;)
  {
	  while(!(USART2->SR & USART_SR_RXNE_Msk));
	  nextByte = USART2->DR;
	  xQueueSend(uart2_BytesReceivedHandle, &nextByte, 0);
  }
  /* USER CODE END polledUartReceive */
}

/* USER CODE BEGIN Header_uartPrintOutTask */
/**
* @brief Function implementing the myTask03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_uartPrintOutTask */
void uartPrintOutTask(void *argument)
{
  /* USER CODE BEGIN uartPrintOutTask */
  char nextByte;
  /* Infinite loop */
  for(;;)
  {
	  xQueueReceive(uart2_BytesReceivedHandle, &nextByte, 5000);
	  SEGGER_SYSVIEW_PrintfHost("%c", nextByte);
  }
  /* USER CODE END uartPrintOutTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
