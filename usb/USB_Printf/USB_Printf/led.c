/*
Title:    led.c
Author:   Markus Knapp <markus@recopter.de> http://recopter.de
Version:  0.1
Software: summon-arm-toolchain
License:

DESCRIPTION:


USAGE:


NOTES:

 */


/* Includes */
#include "led.h"

/**
  * @brief Onboard LED port initialization.
  * @retval None
  */
void initializeLEDs()
{
	GPIO_InitTypeDef GPIO_InitStructureLED;


	// Enable Periph clock for LEDs
	RCC_AHB1PeriphClockCmd(LEDGreen.Clock, ENABLE); // this is the clock for the green LED and all others! To be updated if there is a port change!

	// GPIOPort init, Port D (MEMS LEDs)
	GPIO_InitStructureLED.GPIO_Pin = LEDGreen.Pin | LEDOrange.Pin| LEDRed.Pin| LEDBlue.Pin;
	GPIO_InitStructureLED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructureLED.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructureLED.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructureLED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(LEDGreen.Port, &GPIO_InitStructureLED); // this is the port for the green LED and all others! To be updated if there is a port change!

	// switching all LEDs off
	switchLED(LEDGreen, OFF);
	switchLED(LEDOrange, OFF);
	switchLED(LEDRed, OFF);
	switchLED(LEDBlue, OFF);
}


/**
  * @brief Switch a onboard LED on or off
  * @param led can be LEDGREEN, LEDORANGE, LEDRED or LEDBLUE
  * @param state can be ON or OFF
  * @retval None
  */
void switchLED(led mLED, int state)
{
	if (state == ON)
	{
		GPIO_SetBits(mLED.Port, mLED.Pin);
	}
	else
	{
		GPIO_ResetBits(mLED.Port, mLED.Pin);
	}
}
