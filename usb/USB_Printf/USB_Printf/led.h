/*
 * led.h
 *
 *  Created on: 28.05.2012
 *      Author: markus
 */

#ifndef __LED_H
#define __LED_H

/* Code compatibility */
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes */
#include "stm32f4xx.h"
#include "defaults.h"

/* Functions */
void initializeLEDs();
void switchLED(led mLED, int state);

/* Code compatibility */
#ifdef __cplusplus
}
#endif

#endif /* __LED_H */
