
#ifndef INC_STM32L476XX_GPIO_DRIVER_H_
#define INC_STM32L476XX_GPIO_DRIVER_H_

#include "STM32L476xx.h"

/*
 * Configuration Structure for a GPIO pin
 */
typedef struct{
	uint8_t GPIO_PinNumber;           /*Possible value from @GPIO_PIN_Number */
	uint8_t GPIO_PinMode;             /*Possible value from @GPIO_PIN_MODE */
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/*
 * This is  Handle Structure for a GPIO Pin
 */

typedef struct{
	//Pointer to Hold the base Address of the GPIO Peripheral
	GPIO_RegDef_t *pGPIOx; // This Hold the base address of the GPIO port to which the pin belongs
	GPIO_PinConfig_t GPIO_PinConfig; // This Hold the Pin Configuration Settings
}GPIO_Handle_t;


/*
 * GPIO Pin Number
 * @GPIO_PIN_Number
 */

#define GPIO_PIN_NO_0            0
#define GPIO_PIN_NO_1            1
#define GPIO_PIN_NO_2            2
#define GPIO_PIN_NO_3            3
#define GPIO_PIN_NO_4            4
#define GPIO_PIN_NO_5            5
#define GPIO_PIN_NO_6            6
#define GPIO_PIN_NO_7            7
#define GPIO_PIN_NO_8            8
#define GPIO_PIN_NO_9            9
#define GPIO_PIN_NO_10           10
#define GPIO_PIN_NO_11           11
#define GPIO_PIN_NO_12           12
#define GPIO_PIN_NO_13           13
#define GPIO_PIN_NO_14           14
#define GPIO_PIN_NO_15           15


/*
 * Possible Mode of GPIO Pin
 * @GPIO_PIN_MODE
 */

#define GPIO_MODE_IN           0
#define GPIO_MODE_OUT          1
#define GPIO_MODE_ALTFN        2
#define GPIO_MODE_ANALOG       3
#define GPIO_MODE_IT_FT        4      //IT= Input; FT= Falling Edge
#define GPIO_MODE_IT_RT        5      //IT= Input; RT= Rising Edge
#define GPIO_MODE_IT_RFT       6      // RFT= Rising and Falling Edge triggered

/*
 * GPIO port output type register (GPIOx_OTYPER)
 */
#define GPIO_OP_TYPE_PP        0      //PP-> PUSH PULL
#define GPIO_OP_TYPE_OD        1      //OD-> OPEND DRAIN

/*
 * GPIO port output speed register (GPIOx_OSPEEDR)
 */
#define GPIO_SPEED_LOW         0
#define GPIO_SPEED_MEDIUM      1
#define GPIO_SPEED_FAST        2
#define GPIO_SPEED_HIGH        3

/*
 * GPIO port pull-up/pull-down register Macros
 */
#define GPIO_NO_PUPD           0
#define GPIO_PIN_PU            1
#define GPIO_PIN_PD            2


/*
 *                APIs Supported by this Driver
 * For More Information About the APIs check the function Prototypes
 */

/*
 * Peripheral Clock Setting
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi);

/*
 * Initialize and DeInitialize
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);   //Reset the GPIO Register

/*
 * Data Read And Write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx); //16 ports
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value); // Value will take SET OR RESET()
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ Configuration
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnOrDi); /*configure IRQ Number of GPIO Pin*/
void GPIO_IRQHandling(uint8_t PinNumber);


#endif /* INC_STM32L476XX_GPIO_DRIVER_H_ */
