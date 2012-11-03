/**
*****************************************************************************
**
**  File        : main.c
**
**  Abstract    : main function.
**
**  Functions   : main
**
**  Environment : Atollic TrueSTUDIO(R)
**                STMicroelectronics STM32F4xx Standard Peripherals Library
**
**  Distribution: The file is distributed “as is,” without any warranty
**                of any kind.
**
**  (c)Copyright Atollic AB.
**  You may use this file as-is or modify it according to the needs of your
**  project. Distribution of this file (unmodified or modified) is not
**  permitted. Atollic AB permit registered Atollic TrueSTUDIO(R) users the
**  rights to distribute the assembled, compiled & linked contents of this
**  file as part of an application binary file, provided that it is built
**  using the Atollic TrueSTUDIO(R) toolchain.
**
**
*****************************************************************************
*/

/* Includes */
#include "stm32f4xx.h"
#include "usbd_cdc_core.h"
#include "usbd_cdc.h"
#include "usbd_usr.h"
#include "usbd_desc.h"
/* My Includes */
#include "usart.h" // this is for debugging only (to show messages on a serial console)


/* Private macro */
/* Private variables */

/* Defines */
#define USART1RxBufferSize 		0	//USART1
#define USART2RxBufferSize 		0	//USART2
#define USART3RxBufferSize 		5	//USART3
#define USART6RxBufferSize 		0	//USART6

/* Type definitions */
typedef enum { false, true } bool;


/* Variables */
//USART1
extern uint8_t USART1Buffer[USART1RxBufferSize];
extern __IO uint16_t USART1RxCounter = 0;
extern __IO bool USART1DataReady = false;

//USART2
extern uint8_t USART2Buffer[USART2RxBufferSize];
extern __IO uint16_t USART2RxCounter = 0;
extern __IO bool USART2DataReady = false;

//USART3
extern uint8_t USART3Buffer[USART3RxBufferSize];
extern __IO uint16_t USART3RxCounter = 0;
extern __IO bool USART3DataReady = false;

//USART6
extern uint8_t USART6Buffer[USART6RxBufferSize];
extern __IO uint16_t USART6RxCounter = 0;
extern __IO bool USART6DataReady = false;


/* Private function prototypes */
void Delay(__IO uint32_t nTick);
/* Private functions */
__ALIGN_BEGIN USB_OTG_CORE_HANDLE    USB_OTG_dev __ALIGN_END ;
/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
	STM32F4_Discovery_LEDInit(LED3);
	STM32F4_Discovery_LEDInit(LED4);
	STM32F4_Discovery_LEDInit(LED5);
	STM32F4_Discovery_LEDInit(LED6);
	STM32F4_Discovery_PBInit(BUTTON_USER, BUTTON_MODE_EXTI);

	STM32F4_Discovery_LEDOn(LED3);
	Delay(0xFFFF);

	// usart init (debug console)
	initializeUSART(USART3, 115200);
	receiveUSARTInterrupt(USART3);

	putString(USART3, " Here we go!\r\n");
/*
	//usb init
	USBD_Init(&USB_OTG_dev,
	#ifdef USE_USB_OTG_HS
	  USB_OTG_HS_CORE_ID,
	#else
	  USB_OTG_FS_CORE_ID,
	#endif
	  &USR_desc,
	  &USBD_CDC_cb,
	  &USR_cb);


*/
	int i = 0;

	// send string to laser
	// uint8_t buffer[] = "hello world";
	// cdc_DataTx (buffer, (uint32_t) 11);


  /* Infinite loop */
  // all magic happens in usbd_cdc.c file
  // other file you should look into is usbd_desc.h
  // there is descriptor for your device, ie. what OS will see when you connect the device.
  while (1)
  {
	if (i++ == 0x100000)
    {
 //   	STM32F4_Discovery_LEDToggle(LED4);
    	i = 0;
    }
  }
}

void Delay(__IO uint32_t nTick)
{
  for(; nTick != 0; nTick--);
}
