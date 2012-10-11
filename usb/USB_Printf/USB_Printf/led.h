#ifndef __LED_H
#define __LED_H

/* Code compatibility */
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes */
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

#define ON				ENABLE
#define OFF				DISABLE

/* Typedefs */
typedef struct {
 	GPIO_TypeDef* Port;
 	uint32_t Clock;
 	uint16_t Pin;
 } led;

 /* Variables */
led LEDGreen;
led LEDOrange;
led LEDRed;
led LEDBlue;


/* Functions */
void initializeLEDs();
void switchLED(led mLED, int state);

/* Code compatibility */
#ifdef __cplusplus
}
#endif

#endif /* __LED_H */
