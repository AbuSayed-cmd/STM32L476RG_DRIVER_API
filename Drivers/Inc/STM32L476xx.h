/*
 * STM32L476xx.h
 *
 *  Created on:
 *      Author: ABU SAYED
 */

#ifndef INC_STM32L476XX_H_
#define INC_STM32L476XX_H_

#include <stdint.h>
#define _vo   volatile
/*
 * Base Address of Flash and SRAM Memories
 */

#define FLASH_BASEADDR        0x08000000U /*Address of Flash Memory*/
#define SRAM1_BASEADDR        0x20000000U /*Address of SRAM1 (96KB)*/
#define SRAM2_BASEADDR        0x20001800U /*Address of SRAM2 96X1024=1800(HEX)*/
#define ROM_BASEADDR          0x1FFF0000U /*System Memory*/

#define SRAM                  SRAM1_BASEADDR

/*
 * Base Address of AHBx and APBx Bus Peripheral Address
 */

#define PERIPH_BASE           0x40000000U /*Address of Base Peripheral*/

#define APB1PERIPH_BASEADDR   PERIPH_BASE /*Address of APB1 Bus Peripheral*/
#define APB2PERIPH_BASEADDR   0x40010000U /*Address of APB2 Bus Peripheral*/
#define ABH1PERIPH_BASEADDR   0x40020000U
#define AHB2PERIPH_BASEADDR   0x48000000U /*Address of AHB1 Bus Peripheral*/

/*
 * Base Address of Peripherals which hanging with ABH2 Bus
 */

#define GPIOA_BASEADDR        (AHB2PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR        (AHB2PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR        (AHB2PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR        (AHB2PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR        (AHB2PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR        (AHB2PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR        (AHB2PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR        (AHB2PERIPH_BASEADDR + 0x1C00)


/*
 * Base Address of Peripherals which hanging with ABH1 Bus
 */

#define RCC_BASEADDR          (ABH1PERIPH_BASEADDR + 0x1000) // 0x40021000

/*
 * Base Address of Peripherals which hanging with APB1(80 MHz) Bus
 */

#define I2C1_BASEADDR         (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR         (APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR         (APB1PERIPH_BASEADDR + 0x5C00)

#define CAN1_BASEADDR         (APB1PERIPH_BASEADDR + 0x6400)

#define USART2_BASEADDR       (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR       (APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR        (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR        (APB1PERIPH_BASEADDR + 0x5000)

#define SPI2_BASEADDR         (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR         (APB1PERIPH_BASEADDR + 0x3C00)

/*
 * Base Address of Peripherals which hanging with APB2(80 MHz) Bus
 */

#define SPI1_BASEADDR        (APB2PERIPH_BASEADDR + 0x3000)

#define USART1_BASEADDR      (APB2PERIPH_BASEADDR + 0x3800)

#define EXTI_BASEADDR        (APB2PERIPH_BASEADDR + 0x0400)

#define SYSCFG_BASEADDR      (APB2PERIPH_BASEADDR + 0x0000)


/*********************************Peripheral Register Definition Structure*************************************/

typedef struct{
	_vo uint32_t MODER; // Hold the value of GPIOx_Mode Register
	_vo uint32_t OTYPER;
	_vo uint32_t OSPEEDR;
	_vo uint32_t PUPDR;
	_vo uint32_t IDR;
	_vo uint32_t ODR;
	_vo uint32_t BSRR;
	_vo uint32_t LCKR;
	_vo uint32_t AFR[2]; // AFR Low  and AFR High.

}GPIO_RegDef_t;

/*
 * Peripheral definitions(Peripheral Base Addresses type cast to GPIO_RegDef_t)
 */

#define GPIOA             ((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB             ((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC             ((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD             ((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE             ((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF             ((GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG             ((GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH             ((GPIO_RegDef_t*) GPIOH_BASEADDR)


/*
 * Peripheral definitions(Peripheral Base Addresses type cast to GPIO_RegDef_t)
 * Clock Control Happen from RCC Register
 */

typedef struct{
	_vo uint32_t CR;                        /*Address offset: 0x00 */
	_vo uint32_t ICSCR;                     /*Address offset: 0x04 */
	_vo uint32_t CFGR;                      /*Address offset: 0x08 */
	_vo uint32_t PLLCFGR;                   /*Address offset: 0x0C */
	_vo uint32_t PLLSAI1CFGR;               /*Address offset: 0x10 */
	_vo uint32_t PLLSAI2CFGR;               /*Address offset: 0x14 */
	_vo uint32_t CIER;                      /*Address offset: 0x18 */

	_vo uint32_t CIFR;                      /*Address offset: 0x1C */
	_vo uint32_t CICR;                      /*Address offset: 0x20 */

	_vo uint32_t AHB1RSTR;                  /*Address offset: 0x28 */
	_vo uint32_t AHB2RSTR;                  /*Address offset: 0x2C */
	_vo uint32_t AHB3RSTR;                  /*Address offset: 0x30 */

	_vo uint32_t APB1RSTR1;                 /*Address offset: 0x38 */
	_vo uint32_t APB1RSTR2;                 /*Address offset: 0x3C */
	_vo uint32_t APB2RSTR;                  /*Address offset: 0x40 */

	_vo uint32_t AHB1ENR;                   /*Address offset: 0x48 */
	_vo uint32_t AHB2ENR;                   /*Address offset: 0x4C */
	_vo uint32_t AHB3ENR;                   /*Address offset: 0x50 */


	_vo uint32_t APB1ENR1;                  /*Address offset: 0x58 */
	_vo uint32_t APB1ENR2;                  /*Address offset: 0x5C */
	_vo uint32_t APB2ENR;                   /*Address offset: 0x60 */
	_vo uint32_t AHB1SMENR;                 /*Address offset: 0x68 */
	_vo uint32_t AHB2SMENR;                 /*Address offset: 0x6C */

	_vo uint32_t AHB3SMENR;                 /*Address offset: 0x70 */
	_vo uint32_t APB1SMENR1;                /*Address offset: 0x78 */
	_vo uint32_t APB1SMENR2;                /*Address offset: 0x7C */
	_vo uint32_t APB2SMENR;                 /*Address offset: 0x80 */
	_vo uint32_t CCIPR;                     /*Address offset: 0x88 */
	_vo uint32_t BDCR;                      /*Address offset: 0x90 */
	_vo uint32_t CSR;                       /*Address offset: 0x94 */

}RCC_RegDef_t;

/*
 * Peripheral definitions(Peripheral Base Addresses type cast to RCC_RegDef_t
 * RCC ->AHB1ENR = 25; //
 * *(0x4002 1000 + 0x48) = 25
 */
#define RCC ((RCC_RegDef_t*) RCC_BASEADDR)

/*
 * Clock Enable Macros for GPIOx Peripherals
 */

#define GPIOA_PCLK_EN()  (RCC->AHB2ENR |= (1 << 0 ) )
#define GPIOB_PCLK_EN()  (RCC->AHB2ENR |= (1 << 1 ) )
#define GPIOC_PCLK_EN()  (RCC->AHB2ENR |= (1 << 2 ) )
#define GPIOD_PCLK_EN()  (RCC->AHB2ENR |= (1 << 3 ) )
#define GPIOE_PCLK_EN()  (RCC->AHB2ENR |= (1 << 4 ) )
#define GPIOF_PCLK_EN()  (RCC->AHB2ENR |= (1 << 5 ) )
#define GPIOG_PCLK_EN()  (RCC->AHB2ENR |= (1 << 6 ) )
#define GPIOH_PCLK_EN()  (RCC->AHB2ENR |= (1 << 7 ) )

/*
 * Clock Enable Macros for IC2x Peripherals
 */

#define I2C1_PCLK_EN()  (RCC-> APB1ENR1 |= (1 << 21 ))

/*
 * Clock Enable Macros for SPIx Peripherals
 */

#define SPI1_PCLK_EN()  (RCC-> APB2ENR |= (1 << 12 ))

/*
 * Clock Enable Macros for USARTx Peripherals
 */

#define USART1_PCLK_EN()  (RCC-> APB2ENR |= (1 << 14 ))

/*
 * Clock Enable Macros for SYSCFG Peripherals
 */

#define SYSCFG_PCLK_EN()  (RCC-> APB2ENR |= (1 << 0 ))

/*
 * Clock Disable Macros for GPIOx Peripherals
 */

#define GPIOA_PCLK_DA()  (RCC-> AHB2ENR &= ~(1 << 0 ))
#define GPIOB_PCLK_DA()  (RCC-> AHB2ENR &= ~(1 << 1 ))
#define GPIOC_PCLK_DA()  (RCC-> AHB2ENR &= ~(1 << 2 ))
#define GPIOD_PCLK_DA()  (RCC-> AHB2ENR &= ~(1 << 3 ))
#define GPIOE_PCLK_DA()  (RCC-> AHB2ENR &= ~(1 << 4 ))
#define GPIOF_PCLK_DA()  (RCC-> AHB2ENR &= ~(1 << 5 ))
#define GPIOG_PCLK_DA()  (RCC-> AHB2ENR &= ~(1 << 6 ))
#define GPIOH_PCLK_DA()  (RCC-> AHB2ENR &= ~(1 << 7 ))

/*
 * Clock Disable Macros for IC2x Peripherals
 */

#define I2C1_PCLK_DA()  (RCC-> APB1ENR1 &= ~(1 << 21 ))

/*
 * Clock Disable Macros for SPIx Peripherals
 */

#define SPI1_PCLK_DA()  (RCC-> APB2ENR &= ~(1 << 12 ))

/*
 * Clock Disable Macros for USARTx Peripherals
 */

#define USART1_PCLK_DA()  (RCC-> APB2ENR &= ~(1 << 14 ))

/*
 * Clock Disable Macros for  SYSCFG Peripherals
 */

#define SYSCFG_PCLK_DA()  (RCC-> APB2ENR &= ~(1 << 0 ))

/*
 * Reset GPIOx Peripheral Macros
 */

#define GPIOA_REG_RESET()    do{ (RCC-> AHB2RSTR |= (1 << 0 )); (RCC-> AHB2RSTR &= ~(1 << 0 )); }while(0)
#define GPIOB_REG_RESET()    do{ (RCC-> AHB2RSTR |= (1 << 1 )); (RCC-> AHB2RSTR &= ~(1 << 1 )); }while(0)
#define GPIOC_REG_RESET()    do{ (RCC-> AHB2RSTR |= (1 << 2 )); (RCC-> AHB2RSTR &= ~(1 << 2 )); }while(0)
#define GPIOD_REG_RESET()    do{ (RCC-> AHB2RSTR |= (1 << 3 )); (RCC-> AHB2RSTR &= ~(1 << 3 )); }while(0)
#define GPIOE_REG_RESET()    do{ (RCC-> AHB2RSTR |= (1 << 4 )); (RCC-> AHB2RSTR &= ~(1 << 4 )); }while(0)
#define GPIOF_REG_RESET()    do{ (RCC-> AHB2RSTR |= (1 << 5 )); (RCC-> AHB2RSTR &= ~(1 << 5 )); }while(0)
#define GPIOG_REG_RESET()    do{ (RCC-> AHB2RSTR |= (1 << 6 )); (RCC-> AHB2RSTR &= ~(1 << 6 )); }while(0)
#define GPIOH_REG_RESET()    do{ (RCC-> AHB2RSTR |= (1 << 7 )); (RCC-> AHB2RSTR &= ~(1 << 7 )); }while(0)

/*
 * Enable And Disable Macros
 */

#define ENABLE           1
#define DISABLE          0
#define SET              ENABLE
#define RESET            DISABLE
#define GPIO_PIN_SET     SET
#define GPIO_PIN_RESET   RESET


#endif /* INC_STM32L476XX_H_ */
