#ifndef __LED_H
#define __LED_H

/* Code compatibility */
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes */
#include "stm32f4xx.h"

 /* Functions */
void initializeLEDs();
void switchLED(int led, int state);

/* Code compatibility */
#ifdef __cplusplus
}
#endif

#endif /* __LED_H */
