/*
 * I2c.h
 *
 *  Created on: Aug 26, 2023
 *      Author: Eng Mahmoud Dardery
 */

#ifndef I2C_H_
#define I2C_H_

void TWT_VidMasterInit(void);
void TWT_VidSlaveInit(u8 Copy_U8Address);
void TWT_VidStartCondition(void);
void TWT_VidStopCondition(void);
void TWT_VidSlaveAddAddress(u8 Copy_U8SlaveAdd);
void TWT_VidSlaveAddRead(u8 Copy_U8SlaveAdd);
void TWT_VidMasterSendData(u8 Copy_U8Data);
u8 TWT_VidSlaveReadData(void);
u8 TWT_VidMasterReadData(void);


#endif /* I2C_H_ */
