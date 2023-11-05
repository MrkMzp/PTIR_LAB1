#define F_CPU 16000000UL // такт.сигнал 16 МГц
#include <avr/io.h> 
#include <stdio.h> 
//#include <util/delay.h>

int main(int argc, char **argv)
{
	int delay_ms = 200;

	
	DDRB=0b00100000; //PB5-4-3 - вихід
	PORTB=0x00;

	//Main cycle
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
			delay_ms = delay_ms + 50;
		}
		
		if(PORTB&(1<<PB3))
		{
			delay_ms = delay_ms - 50;
		}	
		
		//Delay
		//Delay(delay_ms);
	}
	return 0;
}
