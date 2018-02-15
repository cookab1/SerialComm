/*
 * SWSerial.h
 *
 * Created: 2/10/2018 8:09:02 PM
 *  Author: Andy
 */ 


#ifndef SWSERIAL_H_
#define SWSERIAL_H_

static int bitTime;
static int rxPin;
static int txPin;

int frameParam;

void init_sw_serial(int rx_pin, int tx_pin, long baudrate, int framing);
void sw_serial_putc(char c);
void switchBaud(long);
void sw_serial_puts(char *);
char sw_serial_getc(void);
void BITBANG(int);
int find(int);

#endif /* SWSERIAL_H_ */