# STM32L476_DRIVER_API(GPIOX, SPI)
## The development of API of GPIOx Peripheral
In this file I have developed a GPIOx Driver API Peripheral for STM32L476RG Nucleo Micro-controller.
By using this Driver API, We can configure -
* GPIOx Initialization
* Enable/Disable GPIOx Port Clock
* Read from GPIOx pin
* Write GPIOx Pin
* Alternate Functionality

## Interrupt Configuration of GPIOx Pin
* Pin must be in Input Mode
* Configure the Edge Trigger such as Rise Triggering or Fall Triggering or RTF, This will done in EXTI Register.
* Enable Interrupt delivery from peripheral to the processor(On Peripheral Side-By using Interrupt Mask Register of EXTI).
* Identify the IRQ number on which the processor accepts the interrupt from the Pin- This can be done by vector Table.
* Confugure the IRQ priority for the identified IRQ number- Need to confugure the NVIC priority register.
* Enable the Interrupt recesption on that IRQ number(By default IRQ number is Disable).
* Implentation of IRQ Handler


## The development of API of SPIx Peripheral
In this file I have developed a SPIx Driver API Peripheral for STM32L476RG Nucleo Micro-controller.
By using this Driver API, We can configure -
* SPIx Initialization
* SPI Tx
* SPI Rx
* SPI Interrupt Configuration and Handling(No Implemented)

**For More info, Please check SPI Readme file**

**NOTE:**
**We can use Header File package developed by STMicroelectronics, can write the progam with less Effort**

## Used Software 
STM32CubeIDE

## Documentation of the Board
* [STM32L476RG](https://www.st.com/en/microcontrollers-microprocessors/stm32l476rg.html)
* [Reference Manual](https://www.st.com/en/microcontrollers-microprocessors/stm32l476rg.html#documentation)
* [Data Sheet](https://www.st.com/en/microcontrollers-microprocessors/stm32l476rg.html#documentation)
* [Schematic ](https://www.st.com/en/microcontrollers-microprocessors/stm32l476rg.html#cad-resources)
