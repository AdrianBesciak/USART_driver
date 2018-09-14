/*
 * USART_driver.c
 *
 * Created: 13.09.2018 23:03:26
 * Author : AdiOS
 */ 

#include <avr/io.h>
#include <util/delay.h>

uint8_t digits[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
uint8_t DP=0x80;
uint8_t error=0x40;

int x;

void welcome(void)
{
	uint8_t h=0x76, e=0x79, l=0x38, o=0x3F;
	PORTB=h;
	PORTD=0x10;
	_delay_ms(500);
	for(uint8_t i=0; i<50; i++)
	{
		if (i%2==0)
		{
			PORTB=e;
			PORTD=0x10;
			_delay_ms(5);
		}
		else
		{
			PORTB=h;
			PORTD<<=1;
			_delay_ms(5);
		}
	}
	for(uint8_t i=0; i<50; i++)
	{
		if (i%3==0)
		{
			PORTB=l;
			PORTD=0x10;
			_delay_ms(5);
		}
		else if(i%3==1)
		{
			PORTB=e;
			PORTD<<=1;
			_delay_ms(5);
		}
		else 
		{
			PORTB=h;
			PORTD<<=1;
			_delay_ms(5);
		}
	}
	for(uint8_t i=0; i<50; i++)
	{
		if (i%4==0)
		{
			PORTB=l;
			PORTD=0x10;
			_delay_ms(5);
		}
		else if(i%4==1)
		{
			PORTB=l;
			PORTD<<=1;
			_delay_ms(5);
		}
		else if(i%4==2)
		{
			PORTB=e;
			PORTD<<=1;
			_delay_ms(5);
		}
		else 
		{
			PORTB=h;
			PORTD<<=1;
			_delay_ms(5);
		}
	}
	for(uint8_t i=0; i<50; i++)
	{
		if (i%4==0)
		{
			PORTB=o;
			PORTD=0x10;
			_delay_ms(5);
		}
		else if(i%4==1)
		{
			PORTB=l;
			PORTD<<=1;
			_delay_ms(5);
		}
		else if(i%4==2)
		{
			PORTB=l;
			PORTD<<=1;
			_delay_ms(5);
		}
		else
		{
			PORTB=e;
			PORTD<<=1;
			_delay_ms(5);
		}
	}
	for(uint8_t i=0; i<50; i++)
	{
		if (i%3==0)
		{
			PORTB=o;
			PORTD=0x20;
			_delay_ms(5);
		}
		else if(i%3==1)
		{
			PORTB=l;
			PORTD<<=1;
			_delay_ms(5);
		}
		else
		{
			PORTB=l;
			PORTD<<=1;
			_delay_ms(5);
		}
	}
	for(uint8_t i=0; i<50; i++)
	{
		if (i%2==0)
		{
			PORTB=o;
			PORTD=0x40;
			_delay_ms(5);
		}
		else
		{
			PORTB=l;
			PORTD<<=1;
			_delay_ms(5);
		}
	}
	PORTB=o;
	PORTD=0x80;
	_delay_ms(500);
	PORTD=0x00;
}

int main(void)
{
	DDRB=0xFF;
	DDRD|=0xF0;
    PORTB=0x01;
	PORTD|=0xF0;
	PORTD=0x10;
	welcome();
	uint8_t digit_on_screen=1;
	x=1234;
    while (1) 
    {
		int temp=x;
		if(x>=10000)
		{
			PORTB=error;
		} else
		{
			for (uint8_t i=1; i<digit_on_screen; i++)
				temp/=10;
			PORTB=digits[temp%10];
		}
		_delay_ms(5);
		PORTD<<=1;
		digit_on_screen++;
		if(digit_on_screen>4)
		{
			PORTD=0x10;
			digit_on_screen=1;
		}
		
			
    }
}

