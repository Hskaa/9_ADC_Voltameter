/******************************************************************/
/******************************************************************/
/***************   		Author : Hossam Medhat		***************/
/***************   		Layer : HAL         		***************/
/***************   		SWC : ADC            		***************/
/***************   		Version : 1.00      		***************/
/******************************************************************/
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Cfg.h"
#include "ADC_Reg.h"


void ADC_voidInit(void)
{
	/*AVCC as reference voltage*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	/*Activate left adjust result*/
	SET_BIT(ADMUX,ADMUX_ADLAR);

	/*Set Prescaler tp divide by 128*/
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);

	/*Enable peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8GetChannelReading(u8 copy_u8channel)
{
	/*Clear the MUX bits in ADMUX register*/
	ADMUX &=0b11100000;

	/*Set the required channel into the MUX bits*/
	ADMUX |= copy_u8channel;

	/*Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*Polling (busy waiting) until the conversion complete flag is set*/
	while ((GET_BIT(ADCSRA , ADCSRA_ADPS0))==0);

	/*CLEAR FALG*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	/*Return read*/
	return ADCH;
}

