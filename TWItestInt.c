/*
 * TWItest2.c
 *
 * Created: 04.07.2016 22:57:40
 *  Author: LV
 */ 

#include "TWItestInt.h"
#include <avr/io.h>
#include "lcd1602.h"
#include "i2c.h"
#include "uart.h"
#include <avr/interrupt.h>

uint8_t B[16];
uint8_t ib = 0;
uint8_t ilcd = 0;

int main(void)
{
	
//	uint8_t ilcd = 0;
	init_UART(9600);
	
	lcd1602_init_alt();
//	lcd1602_send_string("Hello, world!");

//	lcd1602_send_hex(0xAB);

//	lcd1602_goto_xy(0, 1);

//STOP
	init_UART(9600);

	sei();
	
////	while(1);

    while(ilcd < 16)
    {
		if (ilcd < ib) lcd1602_send_hex(B[ilcd++]);

		if (ilcd == 8) 	lcd1602_goto_xy(0, 1);
    }
	
	cli();
}
//---------------------------------------------------------------------------------

ISR(USART_RX_vect) {
	if (ib < 16) {
		B[ib++] = UDR0;
	}
}