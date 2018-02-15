/*
 * SWSerial.c
 *
 * Created: 2/10/2018 10:25:56 PM
 *  Author: john
 */ 


#include "SWSerial.h"
#include <string.h>
#include <avr/io.h>

void delay_usec(unsigned int);

static int pin[] = {53, 52, 51, 50, 10, 11, 12, 13};

void init_sw_serial(int rx_pin, int tx_pin, long baudrate, int framing) {
	rMask = 1 << find(rx_pin);
	tMask = 1 << find(tx_pin);
	bitTime = (1 / baudrate) * 1000000;
	frameParam = framing;
}



void sw_serial_putc(char c){
	BITBANG(0);
	for(int i = 0; i < 8; i++) {
		BITBANG(c & 1);
		c >>= 1;
	}
	BITBANG(1);
	
}

void sw_serial_puts(char *str) {
	int i;
	int length = strlen(str);
	for(i = 0; i < length; i++) {
		sw_serial_putc(str[i]);
	}
}

void BITBANG(int b) {
	if (b) {
		// ON
		PORTB |= 1 << tMask;
	}
	else {
		// OFF
		PORTB &= ~(1 << tMask);
	}
	delay_usec(bitTime);
}

int find(int tPin) {
	for(int i = 0; i < 8; i++) {
		if(tPin == pin[i])
		return i;
	}
	return -1;
}

