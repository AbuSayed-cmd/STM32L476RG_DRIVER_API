/*
 * SPI_Driver.h
 */

#ifndef INC_SPI_DRIVER_H_
#define INC_SPI_DRIVER_H_

#include <stdint.h>
#include "STM32L476xx.h"

typedef struct{
	uint8_t SPI_DeviceMode; // Master or Slave
	uint8_t SPI_BusConfig; // Full Duplex, Half Duplex or Simplex
	uint8_t SPI_SclkSpeed; // User can Define Serial Clock speed
	uint8_t SPI_DFF;       // Data format 16 bit or 8 bit(default 8 bit)
	uint8_t SPI_CPHA;
	uint8_t SPI_CPOL;
	uint8_t SPI_SSM;           // Slave Management System (software or Hardware)
}SPI_Configuration_t;

typedef struct{
	SPI_Configuration_t SPI_Config;
	SPI_RegDef_t *pSPIx;
}SPI_Handle;

// SPI Device Mode(Check Spi control register bit 2(MSTR) )
#define SPI_MasterMode           1
#define SPI_SlaveMode            0   // Default mode

/*SPI Bus Configuration(bit 14(BIDIODE)
 * and 15(BIDIMODE-FULL(0 OR HALF(1) - control register 1, bit 10 RxOnly (simplex)*/
#define SPI_FullDuplex           1
#define SPI_HalfDuplex           2
#define SPI_Simplex_RX           3

//SCLK BR[2:0]: Baud rate control

#define SPI_SCLK_DIV2             0
#define SPI_SCLK_DIV4             1
#define SPI_SCLK_DIV8             2
#define SPI_SCLK_DIV16            3

//DFF(Bit 11 CRCL: CRC length)

#define DFF8_t                   0
#define DFF16_t                  1

//CPOL
#define SPI_CPOL_HIGH            1
#define SPI_CPOL_LOW             0

//CPHA
#define SPI_CPHA_HIGH            1
#define SPI_CPHA_LOW             0

//SSM
#define SPI_SSM_EN               1
#define SPI_SSM_DI               0

#define SPI_RXNE_FLAG            (1 << SPI_SR_RXNE)
#define SPI_TXE_FLAG             (1 << SPI_SR_TXE)
#define SPI_BSY_FLAG             (1 << SPI_SR_BSY)

void SPI_ClkControl(SPI_RegDef_t *pSPIx, uint8_t EorD);
void SPI_Initilization(SPI_Handle *pSPIHandle);
void SPI_Deinitilization(SPI_RegDef_t *pSPIx);

/*
 * Data Send and Receive
 */
void SPI_Send_Data(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t length);
void SPI_Receive_Data(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t length);

/*
 * IRQ Configuration and ISR Handling
 */

void SPI_IRQ_InterruptConfig(uint8_t IQRNumber, uint8_t EorD);
void SPI_IRQ_PriorityConfig(uint8_t IQRNumber, uint32_t IRQPriority);
void SPI_IQR_Handling(uint8_t PinNumver);

#endif /* INC_SPI_DRIVER_H_ */
