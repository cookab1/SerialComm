/*
 * PSerial.h
 *
 * Created: 2/14/2018 7:53:12 PM
 *  Author: Andy
 */ 


#ifndef PSERIAL_H_
#define PSERIAL_H_

static int port;
static long baudrate;
static int framing;
static char data;

void PSerial_open(unsigned int port, long speed, int config);
char PSerial_read(unsigned char port);
void PSerial_write(unsigned char port, char data);


#endif /* PSERIAL_H_ */