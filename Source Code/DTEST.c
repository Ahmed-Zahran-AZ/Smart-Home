#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "motor.h"

#include "DIO_Interface.h"
#include "avr/io.h"
#include "avr/delay.h"

#include "LCD.h"
#include "KPD.h"
#include "Internal_EEPROM.h"

#include "DTEST.h"


    u8 Check_Save_address = 0x30;
    u16 address[4]={0x00,0x04,0x08,0x0c};

    u8 NO_DIG=0,KPD_VALUE=255,KPD_COUNTER=0;
	u8 password[4] , Check_pass[4];
	u8 CHK_COUNT =0;
	u8 First_Number[4],Second_Number[4];

void SmartDoor(void)
{


	u8 Pass_Status;
	LCD_VidInit();
	KPD_VidInit();
	KPD_VALUE=KPD_CHEK;

	Pass_Status=EEPROM_u8CheckValueofAddress(Check_Save_address);
	/*check if first time to enter pass or not */
	if(0xff == Pass_Status)
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
	    	_delay_ms(100);
	    	LCD_VidSendCharPos('*',2,KPD_COUNTER);
	    	password[KPD_COUNTER]=KPD_VALUE;
	    	EEPROM_VidWriteData(address[KPD_COUNTER-1],KPD_VALUE);

	   }
	    EEPROM_VidWriteData(Check_Save_address,0x00);
	    LCD_VidCLR();
	    LCD_VidSendStringPos("Password saved",1,1);

	    /*CHECK PASSWORD*/
	    LCD_VidCLR();
	    _delay_ms(200);
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
	    		    _delay_ms(100);
	    		    LCD_VidSendCharPos('*',2,CHK_COUNT);
	    		    Check_pass[CHK_COUNT]=KPD_VALUE;

	    		    }

	    /*Check password is correct or not*/
	    if(Checking_Pass(password,Check_pass,KPD_COUNTER))
	    	{
	    		     /*starting words */

	    		    LCD_VidCLR();
	    		    LCD_VidSendStringPos("Succesfullogin",1,1);
	    		    for(u8 k=0;k<4;k++)
	    		    {
	    		     LCD_VidSendCharPos('.',1,k+8);
	    		     _delay_ms(500);
	    		    }
	    		     _delay_ms(200);
	    		     LCD_VidCLR();
	    		     LCD_VidSendStringPos("Welcome..",1,1);


	    		     /*Motor will open the Door*/
	    		     Motor();



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
			    if(u8 Checking_Pass_EEPROM(reading from add,Check_pass,CHK_COUNT)) /*hereeeee*/
			    	{
			    		     /*starting words */

			    		    LCD_VidCLR();
			    		    LCD_VidSendStringPos("Succesfullogin",1,1);
			    		    for(u8 k=0;k<4;k++)
			    		    {
			    		     LCD_VidSendCharPos('.',1,k+8);
			    		     _delay_ms(500);
			    		    }
			    		     _delay_ms(200);
			    		     LCD_VidCLR();
			    		     LCD_VidSendStringPos("Welcome..",1,1);


			    		     /*Motor will open the Door*/
			    		     Motor();



	}








}

