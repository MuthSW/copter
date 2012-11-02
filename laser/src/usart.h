/* __USART_H */
#ifndef __USART_H
#define __USART_H

/* Includes */
#include "stm32f4xx.h"

/* Code compatibility */
#ifdef __cplusplus
 extern "C" {
#endif

/* Functions */
void initializeUSART(USART_TypeDef* usart, int baudrate);
void putChar(USART_TypeDef* USART, uint16_t data);
void putString(USART_TypeDef* USART, char* data);
void receiveUSARTInterrupt(USART_TypeDef* USART);

 /* Code compatibility */
#ifdef __cplusplus
}
#endif

#endif /* __USART_H */
