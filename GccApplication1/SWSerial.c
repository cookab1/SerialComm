/*
 * SWSerial.c
 *
 * Created: 2/10/2018 7:54:40 PM
 *  Author: Andy
 */ 

#include "SWSerial.h"
#include <string.h>

static int pin[] = {53, 52, 51, 50, 10, 11, 12, 13};
	
void BITBANG(int);

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


void init_sw_serial(int rx_pin, int tx_pin, long baudrate, int frameing) {
	//rxPin = rx_pin;
	//tMask = 1 << find(tx_pin);
	//switchBaud(baudrate);
	frameParam = frameing;
	bitTime = 104;
	if(bitTime == 104)
		sw_serial_putc('m');
	//(1000000L / baudrate);
}

int find(int tPin) {
	for(int i = 0; i < 8; i++) {
		if(tPin == pin[i])
		return i;
	}
	return -1;
}