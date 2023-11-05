#define F_CPU 16000000UL // такт.сигнал 16 МГц
#include <avr/io.h> 
#include <stdio.h> 
#include <util/delay.h>

int main(int argc, char **argv)
{
	int firstButtomPin = 12;
	int secondButtomPin = 13;
	int delay = 200;

	DDRB=0b00100000; //PB5 - вихід
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
		if(digitalRead(firstButtomPin) && delay <= 1000)
		{
			delay = delay + 50;
		}
		
		if(digitalRead(secondButtomPin) && delay >= 100)
		{
			delay = delay - 50;
		}	
		
	//Delay
		_delay_ms(delay);
		
	}
	return 0;
}
