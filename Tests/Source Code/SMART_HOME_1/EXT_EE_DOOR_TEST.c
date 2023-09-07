/*
 * EXT_EE_DOOR_TEST.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Eng Mahmoud Dardery
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include <avr/delay.h>

#include "DIO_Interface.h"

#include "LCD.h"
#include "KPD.h"
#include "I2c.h"
#include "EEPROM.h"
#include "motor.h"
#include "EXT_EE_DOOR_TEST.h"


u16 Check_Save_address=0 ;
u16 address[4]={1,2,3,4};

u8 NO_DIG=0,KPD_VALUE=255,KPD_COUNTER=0;
u8 password[4] , Check_pass[4];
u8 CHK_COUNT =0;
u8 First_Number[4],Second_Number[4];

void DOOR_Control(void)
{


	//Motor();
	u8 Pass_Status;
		LCD_VidInit();
		KPD_VidInit();
		TWT_VidMasterInit();
		_delay_ms(100);
		KPD_VALUE=KPD_CHEK;

		Pass_Status=EEPROM_VidReadByte(Check_Save_address); //problem
		/*check if first time to enter pass or not */
		if(1 != Pass_Status)
		{
		    /*Set password for first time */

			LCD_VidSendStringPos("Set ur PASS ",1,1);
		    while(1)
		    {
		    	do{
		    		KPD_VALUE=KPD_U8PressedKey();
		    	}while(KPD_VALUE == KPD_CHEK );
		    		KPD_COUNTER++;
		    	if(KPD_VALUE == '&') break;
		    	LCD_VidSendNumberPos(KPD_VALUE,2,KPD_COUNTER);
		    	_delay_ms(50);
		    	LCD_VidSendCharPos('*',2,KPD_COUNTER);
		    	password[KPD_COUNTER]=KPD_VALUE;
		    	EEPROM_VidWriteByte(address[KPD_COUNTER-1],KPD_VALUE);

		   }
		    EEPROM_VidWriteByte(Check_Save_address,1);
		    LCD_VidCLR();
		    LCD_VidSendStringPos("Password saved",1,1);
		    _delay_ms(200);
		    //EEPROM_VidWriteData(Check_Save_address,1);

		    /*CHECK PASSWORD*/
		    LCD_VidCLR();
		    _delay_ms(100);
		    LCD_VidSendStringPos("Check ur PASS ",1,1);
		    KPD_VALUE=KPD_CHEK;
		    while(KPD_VALUE != '&')
		    	{
		    		do{
		    		    KPD_VALUE=KPD_U8PressedKey();
		    		   }while(KPD_VALUE == KPD_CHEK );
		    		    CHK_COUNT++;
		    		    if(KPD_VALUE == '&') break;
		    		    LCD_VidSendNumberPos(KPD_VALUE,2,CHK_COUNT);
		    		    _delay_ms(50);
		    		    LCD_VidSendCharPos('*',2,CHK_COUNT);
		    		    Check_pass[CHK_COUNT]=KPD_VALUE;

		    		    }

		    /*Check password is correct or not*/
		    if(Checking_Pass(password,Check_pass,KPD_COUNTER))
		    	{
		    		     /*starting words */

		    		    LCD_VidCLR();
		    		    LCD_VidSendStringPos("Succesful login",1,1);
		    		    for(u8 k=0;k<6;k++)
		    		    {
		    		     LCD_VidSendCharPos('.',2,k+1);
		    		     _delay_ms(50);
		    		    }
		    		     _delay_ms(50);
		    		     LCD_VidCLR();
		    		     LCD_VidSendStringPos("Welcome..",1,1);

		    		     /*Motor will open the Door*/
		    		     Motor();
				    DIO_VidSetPinValue(PORT_A,PIN_3,DIO_HIGH);



		    	}
		    else
		    {
		    	LCD_VidCLR();
		    	LCD_VidSendStringPos("XXFailed LoginXX",1,1);
		    	_delay_ms(200);
		    	LCD_VidCLR();
		    	LCD_VidSendStringPos("Restart,Then",1,1);
		    	LCD_VidSendStringPos("TRY AGAIN...",2,1);

		    }

		}
		else
		{
			/*CHECK PASSWORD*/
				    LCD_VidCLR();
				    _delay_ms(200);
				    LCD_VidSendStringPos("Enter ur PASS ",1,1);
				    KPD_VALUE=KPD_CHEK;
				    while(KPD_VALUE != '&')
				    	{
				    		do{
				    		    KPD_VALUE=KPD_U8PressedKey();
				    		   }while(KPD_VALUE == KPD_CHEK );
				    		    CHK_COUNT++;
				    		    if(KPD_VALUE == '&') break;
				    		    LCD_VidSendNumberPos(KPD_VALUE,2,CHK_COUNT);
				    		    _delay_ms(100);
				    		    LCD_VidSendCharPos('*',2,CHK_COUNT);
				    		    Check_pass[CHK_COUNT]=KPD_VALUE;

				       }

				    /*Check password is correct or not*/
				    u8 x=0;
				    for(x;x<4;x++)
				    {
				    if(Check_pass[x]==EEPROM_VidReadByte(address[x]))
				    {
				    	x++;
				    }

				    if(x==4)
				    {
				    	LCD_VidCLR();
				        LCD_VidSendStringPos("Succesful login",1,1);
				        for(u8 k=0;k<4;k++)
				    	{
				    	 LCD_VidSendCharPos('.',1,k+14);
				         _delay_ms(500);
				        }
				    	_delay_ms(200);
				    	LCD_VidCLR();
				        LCD_VidSendStringPos("Welcome..",1,1);

				    }

				    }

				     /*Motor will open the Door*/
				    Motor();
				    DIO_VidSetPinValue(PORT_A,PIN_3,DIO_HIGH);


		}




}
