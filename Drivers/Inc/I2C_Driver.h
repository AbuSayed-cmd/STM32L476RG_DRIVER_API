/*
 * I2C_Driver.h
 *
 *  Created on:
 *      Author: ABU SAYED
 */

#ifndef INC_I2C_DRIVER_H_
#define INC_I2C_DRIVER_H_
#include <stdint.h>
#include "STM32L476xx.h"

typedef struct{
	uint32_t I2C_SCLSpeed;
	uint8_t  I2C_DeviceAddress; /* Slave Bit Address is 7 bit, So that why uint8_t, will be initialize by users*/
	uint8_t  I2C_ACKControl;
	uint16_t I2C_FMDutyCycle;
}I2C_Config_t;

typedef struct{
	I2C_RegDef_t *pI2Cx;
	I2C_Config_t I2C_Config;
}I2C_Handle_t;

/*
 * I2C SCL Speed Mode
 */
#define I2C_SCL_SPEED_SM             100000                    /*Standard Mode Upto 100 KhZ */
#define I2C_SCL_SPEED_FM             400000                    /*Standard Mode UPto 400 KhZ */

/*
 * ACK Control
 */
#define I2C_ACK_EN
#define I2C_ACK_DI

#endif /* INC_I2C_DRIVER_H_ */
