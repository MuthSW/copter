/* Includes */
#include "defaults.h"

/* Variables */
extern led ledGreen;
extern led ledOrange;
extern led ledRed;
extern led ledBlue;

/**
  * @brief
  * @retval None
  */
void initDefaults()
{
	// set default LEDs
	ledGreen.port = GPIOD;
	ledGreen.clock = RCC_AHB1Periph_GPIOD;
	ledGreen.pin = GPIO_Pin_12;

	ledOrange.port = GPIOD;
	ledOrange.clock = RCC_AHB1Periph_GPIOD;
	ledOrange.pin = GPIO_Pin_13;

	ledRed.port = GPIOD;
	ledRed.clock = RCC_AHB1Periph_GPIOD;
	ledRed.pin = GPIO_Pin_14;

	ledBlue.port = GPIOD;
	ledBlue.clock = RCC_AHB1Periph_GPIOD;
	ledBlue.pin = GPIO_Pin_15;
}
