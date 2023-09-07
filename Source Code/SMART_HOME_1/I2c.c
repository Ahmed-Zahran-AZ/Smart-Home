#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include <avr/io.h>
#include "I2c.h"


void TWT_VidMasterInit(void)
{
	/*prescaller value*/
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);

	/*frequency -> 400khz*/ /*bit rate*/
	TWBR=2;    //after calculations

	/*enable I2C*/
	SET_BIT(TWCR,TWEN);
}


void TWT_VidSlaveInit(u8 Copy_U8Address)
{
	/*enable acknowledge*/
	SET_BIT(TWCR,TWEA);

	/*write address*/
	TWAR=Copy_U8Address<<1;

	/*enable I2C*/      //repeated cause we did not write it in preprocessor
	SET_BIT(TWCR,TWEN);
}


void TWT_VidStartCondition(void)
{
	/*clear int flag*/
	SET_BIT(TWCR,TWINT);
	/*enable start*/
	SET_BIT(TWCR,TWSTA);

	/*wait hardware action*/
	while(GET_BIT(TWCR,TWINT)==0);
}

void TWT_VidStopCondition(void)
{
	/*clear int flag*/
	SET_BIT(TWCR,TWINT);

	/*Enable stop condition*/
	SET_BIT(TWCR,TWSTO);
}


void TWT_VidSlaveAddAddress(u8 Copy_U8SlaveAdd)
{
	/*write slave address*/
	TWDR=Copy_U8SlaveAdd<<1;     // cause we first bit is for write or read
	/*write operation*/
	CLR_BIT(TWDR,0);
	/*disable start enable condition*/
	CLR_BIT(TWCR,TWSTA);

	/*clear int flag*/
		SET_BIT(TWCR,TWINT);

		SET_BIT(TWCR,TWEN);
	/*wait hardware action*/
		while(GET_BIT(TWCR,TWINT)==0);


}

void TWT_VidSlaveAddRead(u8 Copy_U8SlaveAdd)
{

	/*write slave address*/
		TWDR=Copy_U8SlaveAdd<<1;     // cause we first bit is for write or read
		/*write operation*/
		SET_BIT(TWDR,0);
		/*disable start enable condition*/
		CLR_BIT(TWCR,TWSTA);

		/*clear int flag*/
		SET_BIT(TWCR,TWINT);

		SET_BIT(TWCR,TWEN);
		/*wait hardware action*/
		while(GET_BIT(TWCR,TWINT)==0);


}


void TWT_VidMasterSendData(u8 Copy_U8Data)
{
	/*write data*/
	TWDR=Copy_U8Data;
	/*clear int flag*/
	SET_BIT(TWCR,TWINT);

	SET_BIT(TWCR,TWEN);
	/*wait hardware action*/
	while(GET_BIT(TWCR,TWINT)==0);
}



u8 TWT_VidSlaveReadData(void)
{
	/*SLA+w HAs been recieved ACK has Been Returned */
	while((TWSR&0xf8)!=0x60);
	/*Clear flag*/
	SET_BIT(TWCR,TWINT);

	while((TWSR&0xf8)!=0x80);
	// we didnot set flag here cause the next func will reset
	return TWDR;


}

u8 TWT_VidMasterReadData(void)
{

		SET_BIT(TWCR,TWINT);

		while(GET_BIT(TWCR,TWINT)==0);
		// we did not set flag here cause the next func will reset
		return TWDR;

}
