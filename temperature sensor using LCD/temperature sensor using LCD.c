/*
 * temperature_sensor_using_LCD.c
 *
 *  Author: BAYOUMII
 */ 


#include <avr/io.h>
#include "ADC_driver.h"
#include "LCD.h"
char read_val;
unsigned short temperatue;
int main(void)
{
	LCD_vInit();
	ADC_vinit();
	 LCD_vSend_string("temperature=");
    while(1)
    {
		
        temperatue=(ADC_u16Read()*0.25);
		
		if(temperatue<10)
		{
			LCD_movecursor(1,13);
			LCD_vSend_char(0x30);
			LCD_vSend_char((temperatue%10)+48);
			LCD_vSend_char(0xDF);
			LCD_vSend_char(0x43);
		}
		else if( temperatue<100)
		{
		LCD_movecursor(1,13);
		LCD_vSend_char((temperatue/10)+48);
		LCD_vSend_char((temperatue%10)+48);
		LCD_vSend_char(0XDF);
		LCD_vSend_char(0X43);
		
		}		
		else
		{
		
		}
		
    }
}