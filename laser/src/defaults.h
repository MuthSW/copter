#ifndef __DEFAULTS_H
#define __DEFAULTS_H

/* Code compatibility */
#ifdef __cplusplus
 extern "C" {
#endif

 /* Includes */
 #include "stm32f4xx.h"


/* Typedef */
typedef struct {
	GPIO_TypeDef* port;
	uint32_t clock;
	uint16_t pin;
	TIM_TypeDef* TIM;
	uint16_t CHN;
} motor;

typedef struct {
	GPIO_TypeDef* port;
	uint32_t clock;
	uint16_t pin;
} led;

/* Defines */
#define USART1RxBufferSize 		0	//USART1
#define USART2RxBufferSize 		0	//USART2
#define USART3RxBufferSize 		5	//USART3
#define USART6RxBufferSize 		0	//USART6

#define ON				ENABLE
#define OFF				DISABLE

#define LEDPORT			GPIOD
#define LEDCLOCK		RCC_AHB1Periph_GPIOD
#define LEDGREEN		GPIO_Pin_12
#define LEDORANGE		GPIO_Pin_13
#define LEDRED			GPIO_Pin_14
#define LEDBLUE			GPIO_Pin_15

#define MOTOR1PORT		GPIOB
#define MOTOR1CLOCK		RCC_AHB1Periph_GPIOB
#define MOTOR1PIN		GPIO_Pin_4
#define MOTOR1TIM		TIM3
#define MOTOR1CHN		1

#define MOTOR2PORT		GPIOB
#define MOTOR2CLOCK		RCC_AHB1Periph_GPIOB
#define MOTOR2PIN		GPIO_Pin_5
#define MOTOR2TIM		TIM3
#define MOTOR2CHN		2

#define MOTOR3PORT		GPIOC
#define MOTOR3CLOCK		RCC_AHB1Periph_GPIOC
#define MOTOR3PIN		GPIO_Pin_8
#define MOTOR3TIM		TIM3
#define MOTOR3CHN		3

#define MOTOR4PORT		GPIOC
#define MOTOR4CLOCK		RCC_AHB1Periph_GPIOC
#define MOTOR4PIN		GPIO_Pin_9
#define MOTOR4TIM		TIM3
#define MOTOR4CHN		4

#define MOTOR5PORT		GPIOA
#define MOTOR5CLOCK		RCC_AHB1Periph_GPIOA
#define MOTOR5PIN		GPIO_Pin_1
#define MOTOR5TIM		TIM2
#define MOTOR5CHN		2

#define MOTOR6PORT		GPIOA
#define MOTOR6CLOCK		RCC_AHB1Periph_GPIOA
#define MOTOR6PIN		GPIO_Pin_2
#define MOTOR6TIM		TIM2
#define MOTOR6CHN		3

#define MOTOR7PORT		GPIOA
#define MOTOR7CLOCK		RCC_AHB1Periph_GPIOA
#define MOTOR7PIN		GPIO_Pin_3
#define MOTOR7TIM		TIM2
#define MOTOR7CHN		4

#define MOTOR8PORT		GPIOB
#define MOTOR8CLOCK		RCC_AHB1Periph_GPIOB
#define MOTOR8PIN		GPIO_Pin_7
#define MOTOR8TIM		TIM4
#define MOTOR8CHN		2

#define MOTORPANPORT	GPIOB
#define MOTORPANCLOCK	RCC_AHB1Periph_GPIOB
#define MOTORPANPIN		GPIO_Pin_14
#define MOTORPANTIM		TIM12
#define MOTORPANCHN		1

#define MOTORTILTPORT	GPIOB
#define MOTORTILTCLOCK	RCC_AHB1Periph_GPIOB
#define MOTORTILTPIN	GPIO_Pin_15
#define MOTORTILTTIM	TIM12
#define MOTORTILTCHN	2



/* Functions */
void initDefaults();


/* Code compatibility */
#ifdef __cplusplus
}
#endif

#endif /* __DEFAULTS_H */
