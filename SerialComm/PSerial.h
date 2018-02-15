/*
 * PSerial.h
 *
 * Created: 2/14/2018 7:53:12 PM
 *  Author: Andy
 */ 


#ifndef PSERIAL_H_
#define PSERIAL_H_

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

static char port;
static long baudrate;

void PSerial_open(unsigned char port, long speed, int config);
char PSerial_read(unsigned char port);
void PSerial_write(unsigned char port, char data);
int setUBRR(long);


#endif /* PSERIAL_H_ */