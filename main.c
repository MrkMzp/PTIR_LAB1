#define F_CPU 16000000UL // такт.сигнал 16 МГц
#include <avr/io.h> 
#include <stdio.h> 
#include <util/delay.h>

int main(int argc, char **argv)
{
	int ms = 200;
	
	DDRB=0b00100000; //PB5-4-3 - вихід
	PORTB=0x00;

	while(1)
	{
		// Changing state of the LED 
		if(PORTB&(1<<PB5))
		{ 
			PORTB=0; 
		}else
		{
			PORTB|=1<<PB5;
		}
		
		// Read the buttoms
		if(PORTB&(1<<PB4))
		{
			ms = ms + 50;
		}
		
		if(PORTB&(1<<PB3))
		{
			ms = ms - 50;
		}	
		
		//Delay
		for(int i = 0 ;i < ms ; i++)
		{
			_delay_ms(1);
		}
	}
	return 0;
}
