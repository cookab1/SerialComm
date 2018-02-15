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


int main(void)
{
	int portNum = 0;
	long baud = 19200L;
	int framingParam = SERIAL_8N1;
	
	PSerial_open(portNum, baud, framingParam);
		
    while (1) 
    {
		
    }
}

