/*
 * PSerial.c
 *
 * Created: 2/13/2018 1:50:00 PM
 * Author : john
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "PSerial.h"


typedef struct SERIAL_REGS{
	volatile uint8_t ucsra;
	volatile uint8_t ucsrb;
	volatile uint8_t ucsrc;
	volatile uint8_t rsvd;
	volatile uint16_t ubrr;
	volatile uint8_t udr;	
} SERIAL_REGS;

SERIAL_REGS * serial_port[] = {
	(SERIAL_REGS *)(0xc0), //serial port0
	(SERIAL_REGS *)(0xc8), //serial port1
	(SERIAL_REGS *)(0xd0), //serial port2
	(SERIAL_REGS *)(0x130), //serial port3	
};

void PSerial_open(unsigned int portNum, long speed, int config) {
	port = portNum; //why was this a character?
	baudrate = speed;
	framing = config;
}
/*
UCSRnA 6 is Transmit Complete and 7 is Receive Complete
UCSRnB 3 is Transmit Enable and 4 is Receive Enable
*/
char PSerial_read(unsigned char port) {
	//enable the receiving 
	//UCSRnB bit 4
	UCSR0B |= 1 << 4;
	char c = 0;
	while(!(UCSR0A & 0x80)) {
		//c = read in the data
	}
	return c;
}
void PSerial_write(unsigned char port, char data) {
	//enable the transmitting
	//UCSRnB bit 3
	UCSR0B |= 1 << 3;
	while(!(UCSR0A & 0x40)) {
		//write in the data
	}
}



