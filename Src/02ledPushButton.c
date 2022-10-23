/*
 * 02ledPushButton.c
 */

#include <stdint.h>
#include "STM32L476xx.h"
#include "STM32L476xx_GPIO_DRIVER.h"

void delay(void){
	for(uint32_t i = 0; i <100000; i++);
}


/*
 * GPIOC->MODER &=~(1U<<26);
 * GPIOC->MODER &=~(1U<<27);
 * SET PC13 AS INPUT PIN, BIT POSITION 26 AND 27 WILL 0 0* As PUSH Button always in HIGH(DEFAULT)
 */

int main(void){
	GPIO_Handle_t Led, Button;

	Led.pGPIOx = GPIOA;
	Led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	Led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&Led);

	Button.pGPIOx = GPIOC;
	Button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	Button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	//Button.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Button.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Init(&Button);


	while(1){
		if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13)){
			delay();
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		}
	}
	return 0;

}
