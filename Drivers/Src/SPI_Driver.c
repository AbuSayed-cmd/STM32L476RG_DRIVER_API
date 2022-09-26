/*
 * SPI_Driver.c
 */

#include "SPI_Driver.h"
#include <stdint.h>

void SPI_ClkControl(SPI_RegDef_t *pSPIx, uint8_t EorD){
	if(EorD == ENABLE){
		if( pSPIx == SPI1){
			SPI1_PCLK_EN();
		}else if(pSPIx == SPI2){
			SPI2_PCLK_EN();
		}else if(pSPIx == SPI3){
			SPI3_PCLK_EN();
		}
	}else{
		if( pSPIx == SPI1){
			SPI1_PCLK_DA();
		}else if(pSPIx == SPI2){
			SPI2_PCLK_DA();
		}else if(pSPIx == SPI3){
			SPI3_PCLK_DA();
		}
	}
}

void SPI_Initilization(SPI_Handle *pSPIHandle){
	//1. Configure the SPI_CR1 Register-> Device Mode
	uint32_t temp_reg = 0;
	temp_reg |= pSPIHandle->SPI_Config.SPI_DeviceMode << 2;

	//2. Configure Bus Configuration (Full/Half or Simplex
	if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_FullDuplex){
		//15 Bit(BIDIMODE) Position should be cleared
		temp_reg &= ~(1<<15);
	}else if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_HalfDuplex){
		// 15 Bit(BIDIMODE) Position should be SET
		temp_reg |= (1<<15);
	}else if(pSPIHandle->SPI_Config.SPI_BusConfig){
		// 15 Bit(BIDIMODE) Position should be cleared
		// 10 Bit(RXONLY) Position should be SET
		temp_reg &=~(1<<15);
		temp_reg |= (1<<10);
	}
	//.3 Configure the SCLK
	temp_reg |= pSPIHandle->SPI_Config.SPI_SclkSpeed << 3;

	//4. Configure the DFF
	temp_reg |= pSPIHandle->SPI_Config.SPI_DFF << 11;

	//5. Configure the CPOL
	temp_reg |= pSPIHandle->SPI_Config.SPI_CPOL<< SPI_CR1_CPOL;

	//6. Configure the CHPA
	temp_reg |= pSPIHandle->SPI_Config.SPI_CPHA << SPI_CR1_CPHA;

	// Initialize value of temp_reg into CR1 register
	pSPIHandle->pSPIx->SPI_CR1 = temp_reg;
}



void SPI_Deinitilization(SPI_RegDef_t *pSPIx){
	if(pSPIx == SPI2){
		SPI2_REG_RESET();
	}else if(pSPIx == SPI3){
		SPI3_REG_RESET();
	}
}


/*
 * Data Send and Receive
 */

uint16_t SPI_FlagStaus(SPI_RegDef_t *pSPIx, uint32_t FlagName){
	if(pSPIx->SPI_SR & FlagName){
		return FlagSet;
	}
	return FlagReset;
}

void SPI_Send_Data(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t length){
	while(length > 0){
		// 1. wait Until TXE is set
		//while( !(pSPIx->SPI_SR & (1<<1)));
		while(SPI_FlagStaus(pSPIx, SPI_TXE_FLAG) == FlagReset);

		//2. Check the DFF( Bit 11 CRCL: CRC length) bit in CR1
		if(pSPIx->SPI_CR1 & (1 << 11)){
			// 16 bit DFF
			// 1. Load the data into Data Register
			pSPIx->SPI_DR = *((uint16_t*)pTxBuffer);
			length --;
			length --;
			(uint16_t*)pTxBuffer++;
		}else{
			pSPIx->SPI_DR = *pTxBuffer;
			length --;
			pTxBuffer++;
		}
	}

}
//void SPI_Receive_Data(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t length);
