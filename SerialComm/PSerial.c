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


void PSerial_open(unsigned char portNum, long speed, int framing) {
	port = portNum;
	baudrate = speed;
	serial_port[(int)port]->ubrr = setUBRR(baudrate);
	serial_port[(int)port]->ucsrc = framing;
}
/*
UCSRnA 6 is Transmit Complete and 7 is Receive Complete
UCSRnB 3 is Transmit Enable and 4 is Receive Enable
*/
char PSerial_read(unsigned char port) {
	//enable the receiving 
	//UCSRnB bit 4
	serial_port[port]->ucsrb |= 1 << 4;
	char c = 0;
	while(!(serial_port[port]->ucsra & 0x80)) {
		c = serial_port[port]->udr; //c = read in the data;
	}
	return c;
}
void PSerial_write(unsigned char port, char data) {
	//enable the transmitting
	//UCSRnB bit 3
	serial_port[port]->ucsrb |= 1 << 3;
	while(!(UCSR0A & 0x40)) {
		serial_port[port]->udr = data; //write in the data = data;
	}
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
	}
}



