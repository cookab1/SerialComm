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

<<<<<<< HEAD

=======
>>>>>>> 8c1186f3b94d135e148c49e0191ba0b91e23e0fc
typedef struct SERIAL_REGS{
	volatile uint8_t ucsra;
	volatile uint8_t ucsrb;
	volatile uint8_t ucsrc;
	volatile uint8_t rsvd;
	volatile uint16_t ubrr;
<<<<<<< HEAD
	volatile uint8_t udr;	
=======
	volatile uint8_t udr;
>>>>>>> 8c1186f3b94d135e148c49e0191ba0b91e23e0fc
} SERIAL_REGS;

SERIAL_REGS * serial_port[] = {
	(SERIAL_REGS *)(0xc0), //serial port0
	(SERIAL_REGS *)(0xc8), //serial port1
	(SERIAL_REGS *)(0xd0), //serial port2
<<<<<<< HEAD
	(SERIAL_REGS *)(0x130), //serial port3	
};

void PSerial_open(unsigned int portNum, long speed, int config) {
	port = portNum; //why was this a character?
	baudrate = speed;
	framing = config;
=======
	(SERIAL_REGS *)(0x130), //serial port3
};

static unsigned char port;
static long baudrate;

void PSerial_open(unsigned char portNum, long speed, int framing) {
	port = portNum;
	baudrate = speed;
	serial_port[port]->ubrr = setUBRR(baudrate);
	serial_port[port]->ucsrc = framing;
	//enable the receiving
	//UCSRnB bit 4
	serial_port[port]->ucsrb |= (1 << 4);
	//enable the transmitting
	//UCSRnB bit 3
	serial_port[port]->ucsrb |= (1 << 3);
>>>>>>> 8c1186f3b94d135e148c49e0191ba0b91e23e0fc
}
/*
UCSRnA 6 is Transmit Complete and 7 is Receive Complete
UCSRnB 3 is Transmit Enable and 4 is Receive Enable
*/
char PSerial_read(unsigned char port) {
<<<<<<< HEAD
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
=======
	char c = 0;
	while(!(serial_port[port]->ucsra & (1 << 7))) {
	}
	c = serial_port[port]->udr; //c = read in the data;
	return c;
}
void PSerial_write(unsigned char port, char data) {
	while(!(serial_port[port]->ucsra & (1 << 5))) {
	}
	serial_port[port]->udr = data; //write in the data = data;
}
int setUBRR(long baud) {
	switch(baud){
		case 2400:
			return 416;
			break;
		case 4800:
			return 207;
			break;
		case 9600:
			return 103;
			break;
		case 14400:
			return 68;
			break;
		case 19200:
			return 51;
			break;
		case 28800:
			return 34;
			break;
		case 38400:
			return 25;
			break;
		case 57600:
			return 16;
			break;
		case 76800:
			return 12;
			break;
		case 115200:
			return 8;
			break;
		case 230400:
			return 3;
			break;
		case 250000:
			return 3;
			break;
		default:
			return -1;
>>>>>>> 8c1186f3b94d135e148c49e0191ba0b91e23e0fc
	}
}



