
#include <stdint.h>
#include "STM32L476xx.h"
#include "STM32L476xx_GPIO_DRIVER.h"

void delay(void){
	for(uint32_t i = 0; i <100000; i++);
}

int main(void){
	GPIO_Handle_t Led;

	Led.pGPIOx = GPIOA;
	Led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	Led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&Led);

	while(1){
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		delay();
	}
	return 0;

}

