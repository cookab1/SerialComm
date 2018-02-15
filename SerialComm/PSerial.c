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
	port = portNum;
	baudrate = speed;
	framing = config;
}
char PSerial_read(unsigned char port) {
	
}
void PSerial_write(unsigned char port, char data) {
	
}



