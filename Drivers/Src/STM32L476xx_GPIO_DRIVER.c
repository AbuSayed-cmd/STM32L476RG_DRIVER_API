
#include "STM32L476xx_GPIO_DRIVER.h"

/*
 *            ****APIs Supported by this Driver****
 * For More Information About the APIs check the function Prototypes
 */

/******************************************************************
 * Peripheral Clock Setting
 * @Function Name      - GPIO_PeriClockControl
 *
 * @brief              - The function enables or disables peripheral clock for given GPIO port
 *
 * @param[in]          - Base Address of GPIO Peripheral
 * @param[in]          - Enable or Disable Macros
 * @param[in]          -
 *
 * @result[in]         - None
 *
 * @Note[in]           - None
 *
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
	{
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_EN();
		}else if(pGPIOx == GPIOB){
			GPIOB_PCLK_EN();
		}else if(pGPIOx == GPIOC){
			GPIOC_PCLK_EN();
		}else if (pGPIOx == GPIOD){
			GPIOD_PCLK_EN();
		}else if (pGPIOx == GPIOE){
			GPIOE_PCLK_EN();
		}else if (pGPIOx == GPIOF){
			GPIOF_PCLK_EN();
		}else if (pGPIOx == GPIOG){
			GPIOG_PCLK_EN();
		}else if (pGPIOx == GPIOH){
			GPIOH_PCLK_EN();
		}
	}else{
		if(pGPIOx == GPIOA){
				GPIOA_PCLK_DA();
				}else if(pGPIOx == GPIOB){
					GPIOB_PCLK_DA();
				}else if(pGPIOx == GPIOC){
					GPIOC_PCLK_DA();
				}else if (pGPIOx == GPIOD){
					GPIOD_PCLK_DA();
				}else if (pGPIOx == GPIOE){
					GPIOE_PCLK_DA();
				}else if (pGPIOx == GPIOF){
					GPIOF_PCLK_DA();
				}else if (pGPIOx == GPIOG){
					GPIOG_PCLK_DA();
				}else if (pGPIOx == GPIOH){
					GPIOH_PCLK_DA();
				}
	}
}


/******************************************************************
 * Peripheral Clock Setting
 * @Function Name      - GPIO_Init
 *
 * @brief              - Configure the Mode of GPIO Pin
 *                     - Configure the Speed
 *                     - Configure Pull-Up/Pull-down(pupd) Settings
 *                     - Configure the Output Type
 *                     - Configure Alternate Functionality
 *
 * @param[in]          - Base Address of GPIO Peripheral
 * @param[in]          - Enable or Disable Macros
 * @param[in]          -
 *
 * @result[in]         - None
 *
 * @Note[in]           - None
 *
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){

	uint32_t temp = 0;

	//configure the mode of GPIO pin
	if(pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){
		temp =(pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->MODER |= temp;
	}else{
		//Code for Interrupt Mode
	}

	temp = 0;
	// Configure the Speed
	temp =( pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	temp = 0;
	//Configure PUPD Settings
	temp =( pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	temp = 0;
	//Configure the Output Type
	temp =( pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	temp = 0;
	//Configure The Alternate Functionality
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode == GPIO_MODE_ALTFN){
		// Configure the Alternate Function Register
		uint32_t temp1, temp2;
		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~ (0xF << (4 * temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode <<(4 * temp2));
	}
}

/*
 * Initialize and DeInitialize
 */


void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){
	//Reset the GPIO Register
	if(pGPIOx == GPIOA){
		GPIOA_REG_RESET();
	}else if(pGPIOx == GPIOB){
		GPIOB_REG_RESET();
	}else if(pGPIOx == GPIOC){
		GPIOC_REG_RESET();
	}else if (pGPIOx == GPIOD){
		GPIOD_REG_RESET();
	}else if (pGPIOx == GPIOE){
		GPIOE_REG_RESET();
	}else if (pGPIOx == GPIOF){
		GPIOF_REG_RESET();
	}else if (pGPIOx == GPIOG){
		GPIOG_REG_RESET();
	}else if (pGPIOx == GPIOH){
		GPIOH_REG_RESET();
	}
}

/*
 * Data Read And Write
 */

/******************************************************************
 * Peripheral Clock Setting
 * @Function Name      - GPIO_ReadFromInputPin
 *
 * @brief              -
 *
 *
 * @param[in]          -
 * @param[in]          -
 * @param[in]          -
 *
 * @result[in]         - 0 or 1
 *
 * @Note[in]           - None
 *
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}

/******************************************************************
 * Peripheral Clock Setting
 * @Function Name      - GPIO_ReadFromInputPort
 *
 * @brief              -
 *
 *
 * @param[in]          -
 * @param[in]          -
 * @param[in]          -
 *
 * @result[in]         - 0 or 1
 *
 * @Note[in]           - None
 *
 */

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	//16 ports

	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);
	return value;
}


void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value){
	// Value will take SET OR RESET()
	if(Value == GPIO_PIN_SET){
		// Write 1 to the output data register at the bit field corresponding pin number
		pGPIOx->ODR |= (1 << PinNumber);
	}else{
		//Write 0
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value){
	pGPIOx->ODR = Value;
}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
	pGPIOx->ODR ^= (1 << PinNumber);
}

/*
 * IRQ Configuration
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnOrDi); /*configure IRQ Number of GPIO Pin*/
void GPIO_IRQHandling(uint8_t PinNumber);

