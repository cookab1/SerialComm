/*
 * Project3.c
 *
 * Created: 2/10/2018 7:19:02 PM
 * Author: Andy Cook
 * Author: John Osborne
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include "EmSys.h"
#include "SWSerial.h"

//DDRK = 0x800;
//PIN11 is the receiving pin I think
//When does it start
//When does it stop
//What does it do in the middle

void delay_usec(unsigned int);

int main(void) {
	//DDRB |= (1 << PB6);
	DDRB = 0;
	
	long baudrate = 9600L;  // initially--can change after this works
	int tx_pin = 12;
	int rx_pin = 11;
	int framing = SERIAL_8N1;
	
	init_sw_serial(rx_pin, tx_pin, baudrate, framing);  // this is your function
	init_sw_serial_getc_test(baudrate, framing);   // library function: note we need the baudrate and framing here

	debug_init();
	sw_serial_getc();  // throw away first char
	while(1) {
		char c = sw_serial_getc();
		// convert any alpha char c to opposite case
		// you'll need a little code here to do this...
		if (c >= 0x41 && c <= 0x5A) {
			c += 0x20;
		}
		else {
			c -= 0x20;
		}
		sw_serial_putc(c);
		test_sw_serial_getc();   // library test function
	}
}
char sw_serial_getc(void) {
	char c = 0;
	int i;
	for(i = 0; i < 8; i++) {
		if (i == 0)
		c = PINB;
		else
		c |= (PINB << i);
		delay_usec(bitTime);
	}
	BITBANG(0);
	return c;
}