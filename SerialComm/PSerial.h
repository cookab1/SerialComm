/*
 * PSerial.h
 *
 * Created: 2/14/2018 7:53:12 PM
 *  Author: Andy
 */ 


#ifndef PSERIAL_H_
#define PSERIAL_H_

char Pserial_open(unsigned char port, long speed, int config);
char PSerial_read(unsigned char port);
void PSerial_write(unsigned char port, char data);


#endif /* PSERIAL_H_ */