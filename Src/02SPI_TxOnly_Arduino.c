/*
 * SPI_TxOnly_Arduino.
 */

#include <string.h>
#include "STM32L476xx.h"
#include "SPI_Driver.h"


/*
 * PB12 -- SPI2_NSS
 * PB13 -- SPI2_SCK
 * PB14 -- SPI2_MISO
 * PB15 -- SPI2_MOSI
 * AF5 -- Alternate Functionality mode
 */
void SPI_GPIOInit(void){
	GPIO_Handle_t SPI_PIN;

	SPI_PIN.pGPIOx = GPIOB;
	SPI_PIN.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPI_PIN.GPIO_PinConfig.GPIO_PinAltFunMode = 5;
	SPI_PIN.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	SPI_PIN.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	SPI_PIN.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	//SCLK
	SPI_PIN.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GPIO_Init(&SPI_PIN);

	//MOSI
	SPI_PIN.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GPIO_Init(&SPI_PIN);

	//MISO
	//SPI_PIN.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	//GPIO_Init(&SPI_PIN);

	//NSS
	SPI_PIN.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GPIO_Init(&SPI_PIN);
}


void SPI2_Init(void){
	SPI_Handle SPI2_Handle;
	SPI2_Handle.pSPIx = SPI2;
	SPI2_Handle.SPI_Config.SPI_BusConfig = SPI_FullDuplex;
	SPI2_Handle.SPI_Config.SPI_DeviceMode = SPI_MasterMode;
	SPI2_Handle.SPI_Config.SPI_SclkSpeed = SPI_SCLK_DIV8; // Generate Serial Clock of 2Mhz
	SPI2_Handle.SPI_Config.SPI_DFF = DFF8_t;
	SPI2_Handle.SPI_Config.SPI_CPOL = SPI_CPOL_LOW;
	SPI2_Handle.SPI_Config.SPI_CPHA = SPI_CPHA_LOW;
	SPI2_Handle.SPI_Config.SPI_SSM = SPI_SSM_DI; // Hardware Slave Management Enable for NSS Pin

	SPI_Initilization(&SPI2_Handle);
}

 void GPIO_PUSH_BUTTON(void){
	 GPIO_Handle_t Button;
	 Button.pGPIOx = GPIOC;
	 Button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	 Button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	 //Button.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	 Button.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	 GPIO_Init(&Button);
}

 void delay(void){
 	for(uint32_t i = 0; i <500000/2; i++);
 }


int main (){
	char USER_DATA[] ="Hello";
	GPIO_PUSH_BUTTON();
	SPI_GPIOInit();
	SPI2_Init();

	/*
	 * SSOE = 1, NSS = output Enable
	 */
	 SPI_SSOE_Config(SPI2, ENABLE);
	while(1){
		while (!GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13));

		delay();

		//Enable SPI2 Peripheral
		SPI_PeripheraControl(SPI2, ENABLE);

		//Send the length of data
		uint8_t dataLen = strlen(USER_DATA);
		SPI_Send_Data(SPI2,&dataLen,1);

		//To send the data
		SPI_Send_Data(SPI2,(uint8_t*)USER_DATA,strlen(USER_DATA));

		while(SPI_GetFlagStatus(SPI2, SPI_BSY_FLAG));
		SPI_PeripheraControl(SPI2, DISABLE);
	}
	return 0;
}
