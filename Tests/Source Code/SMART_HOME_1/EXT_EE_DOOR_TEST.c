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

#define EEPROM_ENABLE 0
u16 Check_Save_address = 0;
u16 address[4] = { 1, 2, 3, 4 };

u8 NO_DIG = 0, KPD_VALUE = 255, KPD_COUNTER = 0;
u8 password[4], Check_pass[4];

u8 First_Number[4], Second_Number[4];
u8 pass_wrong_count = 0;
void DOOR_Control(void) {

	u8 pin[4] = {1,2,3,4};
	//Motor();
	u8 Pass_Status;

	//TWT_VidMasterInit();
	//_delay_ms(100);


	Pass_Status = 0; //problem
	/*check if first time to enter pass or not */
#if EEPROM_ENABLE
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
		    	//EEPROM_VidWriteByte(address[KPD_COUNTER-1],KPD_VALUE);

		   }
		    //EEPROM_VidWriteByte(Check_Save_address,1);
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
#endif

	/*CHECK PASSWORD*/
while(1){
	u8 CHK_COUNT = 0;
	LCD_VidInit();
	KPD_VidInit();
	KPD_VALUE = KPD_CHEK;
	LCD_VidSendStringPos("Enter the PIN ", 1, 1);
	KPD_VALUE = KPD_CHEK;
	while (KPD_VALUE != '&') {
		do {
			KPD_VALUE = KPD_U8PressedKey();
		} while (KPD_VALUE == KPD_CHEK);

		if (KPD_VALUE == '&'){
			break;
		}
		CHK_COUNT++;
		LCD_VidSendNumberPos(KPD_VALUE, 2, CHK_COUNT);
		_delay_ms(50);
		LCD_VidSendCharPos('*', 2, CHK_COUNT);
		Check_pass[CHK_COUNT-1] = KPD_VALUE;

	}
	if (Checking_Pass(pin, Check_pass, 4)) {
		/*starting words */

		LCD_VidCLR();
		LCD_VidSendStringPos("Successful login", 1, 1);
		for (u8 k = 0; k < 6; k++) {
			LCD_VidSendCharPos('.', 2, k + 1);
			_delay_ms(50);
		}
		_delay_ms(50);
		LCD_VidCLR();
		LCD_VidSendStringPos("Welcome..", 1, 1);

		/*Motor will open the Door*/
		Motor();
		DIO_VidSetPinValue(PORT_A, PIN_3, DIO_HIGH);
		break;
	}
	else {
		LCD_VidCLR();
		LCD_VidSendStringPos("XXFailed LoginXX", 1, 1);
		pass_wrong_count++;
		_delay_ms(200);
		LCD_VidCLR();
		if(pass_wrong_count <3){
		LCD_VidSendStringPos("Restart,Then", 1, 1);
		LCD_VidSendStringPos("TRY AGAIN...", 2, 1);
		_delay_ms(1000);
		LCD_VidCLR();
		}
		else{
			LCD_VidSendStringPos("3 wrong tries",1,1);
			LCD_VidSendStringPos("Exiting....",2,1);
			_delay_ms(2000);
			while(1);
		}
	}

}
}



