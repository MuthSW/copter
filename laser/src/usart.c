/* Includes */
#include "usart.h"

/**
  * @brief  USART initialization
  * @param  USART Name of the USART Port
  * @param  BaudRate  Baudrate for the specific port
  * @retval None
  */
void initializeUSART(USART_TypeDef* USART, int BaudRate){
	GPIO_TypeDef* USARTPort;
	uint16_t USARTPinTX;
	uint16_t USARTPinRX;
	uint32_t USARTClock;
	uint8_t USARTAF;
	uint8_t USARTRXPinSource;
	uint8_t USARTTXPinSource;
	uint32_t USARTPortClock;
	USART_InitTypeDef USARTInitStructure;
	GPIO_InitTypeDef GPIOInitStructure;

	//Pin selection
	if (USART == USART1){
		USARTPort = GPIOA;
		USARTPinTX = GPIO_Pin_9;
		USARTPinRX = GPIO_Pin_10;
		USARTAF = GPIO_AF_USART1;
		USARTRXPinSource = GPIO_PinSource10;
		USARTTXPinSource = GPIO_PinSource9;
		USARTClock = RCC_APB2Periph_USART1;
		USARTPortClock = RCC_AHB1Periph_GPIOA;

	} else if (USART == USART2){
		USARTPort = GPIOA;
		USARTPinTX = GPIO_Pin_2;
		USARTPinRX = GPIO_Pin_3;
		USARTAF = GPIO_AF_USART2;
		USARTRXPinSource = GPIO_PinSource3;
		USARTTXPinSource = GPIO_PinSource2;
		USARTClock = RCC_APB1Periph_USART2;
		USARTPortClock = RCC_AHB1Periph_GPIOA;

	} else if (USART == USART3){
		USARTPort = GPIOD;
		USARTPinTX = GPIO_Pin_8;
		USARTPinRX = GPIO_Pin_9;
		USARTAF = GPIO_AF_USART3;
		USARTRXPinSource = GPIO_PinSource9;
		USARTTXPinSource = GPIO_PinSource8;
		USARTClock = RCC_APB1Periph_USART3;
		USARTPortClock = RCC_AHB1Periph_GPIOD;

	} else{
		USARTPort = GPIOC;
		USARTPinTX = GPIO_Pin_6;
		USARTPinRX = GPIO_Pin_7;
		USARTAF = GPIO_AF_USART6;
		USARTRXPinSource = GPIO_PinSource7;
		USARTTXPinSource = GPIO_PinSource6;
		USARTClock = RCC_APB2Periph_USART6;
		USARTPortClock = RCC_AHB1Periph_GPIOC;

	}

	//Initializing
	USARTInitStructure.USART_BaudRate = BaudRate;
	USARTInitStructure.USART_WordLength = USART_WordLength_8b;
	USARTInitStructure.USART_StopBits = USART_StopBits_1;
	USARTInitStructure.USART_Parity = USART_Parity_No;
	USARTInitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USARTInitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	//Configure GPIO and USART Clock
	RCC_AHB1PeriphClockCmd(USARTPortClock, ENABLE);
	if ((USART == USART1) || (USART == USART6)) {
		RCC_APB2PeriphClockCmd(USARTClock, ENABLE);
	} else {
		RCC_APB1PeriphClockCmd(USARTClock, ENABLE);
	}

	//Configure USART AF
	GPIO_PinAFConfig(USARTPort, USARTRXPinSource, USARTAF);
	GPIO_PinAFConfig(USARTPort, USARTTXPinSource, USARTAF);

	//Configure Ports
	//TX
	GPIOInitStructure.GPIO_Pin = USARTPinTX;
	GPIOInitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIOInitStructure.GPIO_OType = GPIO_OType_PP;
	GPIOInitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIOInitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIOInitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(USARTPort, &GPIOInitStructure);

	//RX
	GPIOInitStructure.GPIO_Pin = USARTPinRX;
	GPIOInitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_Init(USARTPort, &GPIOInitStructure);

	USART_Init(USART, &USARTInitStructure);
	USART_Cmd(USART, ENABLE);
}

/**
  * @brief  Sends a character to USART
  * @param  USART Name of the USART Port
  * @param  data  Character which will be send
  * @retval None
  */
void putChar(USART_TypeDef* USART, uint16_t data){

	USART_SendData(USART, data);
	while (USART_GetFlagStatus(USART,USART_FLAG_TC) == RESET); // Wait until transmission is finished
}

/**
  * @brief  Sends a string to USART
  * @param  USART Name of the USART Port
  * @param  data  String which will be send
  * @retval None
  */
void putString(USART_TypeDef* USART, char* data){

	while(*data != '\0'){	//Check of string end
		putChar(USART, *data++);
	}
}

/**
  * @brief  Receives string from USART and writes it tom memory
  * @param  USART Name of the USART Port
  * @retval None
  */
void receiveUSARTInterrupt(USART_TypeDef* USART){
        NVIC_InitTypeDef NVIC_InitStructure;

        //Address selection
        if (USART == USART1){

                NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
                USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
        } else if (USART == USART2){

                NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
                USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
        } else if (USART == USART3){

                NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
                USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
        } else{

                NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;
                USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);
        }

        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
        NVIC_Init(&NVIC_InitStructure);
}
