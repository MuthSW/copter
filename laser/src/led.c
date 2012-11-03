/* Includes */
#include "led.h"
#include "defaults.h"


/**
  * @brief Onboard LED port initialization.
  * @retval None
  */
void initializeLEDs()
{
	GPIO_InitTypeDef GPIO_InitStructureLED;


	// Enable Periph clock for LEDs
	RCC_AHB1PeriphClockCmd(LEDCLOCK	, ENABLE);

	// GPIOPort init, Port D (MEMS LEDs)
	GPIO_InitStructureLED.GPIO_Pin = LEDGREEN | LEDORANGE| LEDRED| LEDBLUE;
	GPIO_InitStructureLED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructureLED.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructureLED.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructureLED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(LEDPORT, &GPIO_InitStructureLED);

	// switching all LEDs off
	switchLED(LEDBLUE, OFF);
	switchLED(LEDGREEN, OFF);
	switchLED(LEDORANGE, OFF);
	switchLED(LEDRED, OFF);
}


/**
  * @brief Switch a onboard LED on or off
  * @param led can be LEDGREEN, LEDORANGE, LEDRED or LEDBLUE
  * @param state can be ON or OFF
  * @retval None
  */
void switchLED(int led, int state)
{
	if (state == ON)
	{
		GPIO_SetBits(LEDPORT, led);
	}
	else
	{
		GPIO_ResetBits(LEDPORT, led);
	}
}
