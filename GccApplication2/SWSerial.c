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

void init_sw_serial(int rx_pin, int tx_pin, long baudrate, int framing) {
	rxPin = find(rx_pin);
	txPin = find(tx_pin);
	switchBaud(baudrate);
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
		
	}
}

void switchBaud(long baudrate) {
	//bitTime = (1 / baudrate) * 1000000;
}

void BITBANG(int b) {
	if (b) {
		// ON
		PORTB |= txPin;
	}
	else {
		// OFF
		PORTB &= ~txPin;
	}
	delay_usec(104);
}

int find(int tPin) {
	for(int i = 0; i < 8; i++) {
		if(tPin == pin[i])
		return i;
	}
	return -1;
}

