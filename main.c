#include "STD_TYPES.h"
#include <util/delay.h>

#include "PORT_Interface.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "LCD_Interface.h"
/*Contrlling LM35 */
/*
void main (void)
{

	PORT_voidInit();

	ADC_voidInit();

	LCD_voidInit();

	u16 Millivolt;


	while(1)
	{
		u16 Local_u8ADCReading = ADC_u8GetChannelReading(3);
		u16 Millivolt = ((u32)5000*Local_u8ADCReading)/256;

		u8 temp = Millivolt/10;
		LCD_voidWriteNumber(temp);

		_delay_ms(700);
		LCD_voidClearLCD();
	}
}
 */

/*Controlling LEDs with LDR*/

void main (void)
{

	PORT_voidInit();

	ADC_voidInit();

	LCD_voidInit();

	u16 Millivolt;


	while(1)
	{
		u16 Local_u8ADCReading = ADC_u8GetChannelReading(3);
		if (Local_u8ADCReading >0 &&Local_u8ADCReading <40 )
		{
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN0 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN1 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN2 , DIO_HIGH);
			_delay_ms(700);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN0 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN1 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN2 , DIO_LOW);

		}
		else if (Local_u8ADCReading>40 &&Local_u8ADCReading<130)
		{
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN0 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN1 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN2 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN3 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN4 , DIO_LOW);
			_delay_ms(700);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN0 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN1 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN2 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN3 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN4 , DIO_HIGH);

		}
		else if (Local_u8ADCReading>130)
		{
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN0 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN1 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN2 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN3 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN4 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN5 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN6 , DIO_LOW);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN7 , DIO_LOW);
			_delay_ms(700);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN0 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN1 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN2 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN3 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN4 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN5 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN6 , DIO_HIGH);
			DIO_u8SetPinValue(DIO_PORTC , DIO_PIN7 , DIO_HIGH);

		}


		LCD_voidWriteNumber(Local_u8ADCReading);

		_delay_ms(700);
		LCD_voidClearLCD();
	}
}

