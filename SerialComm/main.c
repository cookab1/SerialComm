/*
 * SerialComm.c
 *
 * Created: 2/13/2018 2:41:06 PM
 * Author : cookab1
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "PSerial.h"
#include "EmSys.h"

void daisy_chain_Test();
unsigned char portNum;
long baud;
int framingParam;

int main(void)
{
	portNum = 0;
	baud = 19200L;
	framingParam = SERIAL_8N1;
	int daisyChain = 0; //to turn on daisy chain, set to 1
	
	if(daisyChain) {
		for(int i = 0; i < 4; i++)
			PSerial_open(i, baud, framingParam);
	} 
	else	
		PSerial_open(portNum, baud, framingParam);
		
    while (1) 
    {
		if(daisyChain)
			daisy_chain_Test();
		else {
			char rx_bit = PSerial_read(portNum);
			PSerial_write(portNum, rx_bit);
		}
	}
}

void daisy_chain_Test() {

	char rx_bit = PSerial_read(0);
	PSerial_write(1, rx_bit);
	rx_bit = PSerial_read(2);
	PSerial_write(2, rx_bit);
	rx_bit = PSerial_read(3);
	PSerial_write(3, rx_bit);
	rx_bit = PSerial_read(1);
	PSerial_write(0, rx_bit);
}

