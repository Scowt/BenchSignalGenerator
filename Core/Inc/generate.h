/*
 * generate.h
 *
 *  Created on: Oct 31, 2020
 *      Author: User
 */



#ifndef INC_GENERATE_H_
#define INC_GENERATE_H_
#include <stdint.h>
#include "IODefs.h"

#define FREQUENCY_MODIFIER	0b10000000000000000000000000000
#define DDS_CTRL_SEL1		0xF
#define DDS_CTRL_SEL1		0xE
#define DDS_CTRL_B28		0xD
#define DDS_CTRL_HLB		0xC
#define DDS_CTRL_FSEL		0xB
#define DDS_CTRL_PSEL		0xA
#define DDS_CTRL_PIN		0x9
#define DDS_CTRL_RST		0x8
#define DDS_CTRL_SLEEP1		0x7
#define DDS_CTRL_SLEEP12	0x6
#define DDS_CTRL_OPBITEN	0x5
#define DDS_CTRL_SIGN		0x4
#define DDS_CTRL_DIV2		0x3
#define DDS_CTRL_RESERVED	0x2
#define DDS_CTRL_MODE		0x1
#define DDS_CTRL_RESERVED0	0x0
#define DDS_FREQ1			0xF
#define DDS_FREQ0			0xE



struct Parameters
	{
		uint32_t Frequency;		//in hertz
		uint8_t WaveType;		//using WAVE defs
		float Amplitude;		//in volts
		float Phase;			//in seconds
		float Delay;			//between cycles? or peaks? //TODO decide
		float Shift;			//Vertical shift
		uint8_t Rectification;	//None / positive / negative
	};
uint8_t GenerateWave(struct Parameters SignalParameters);
uint8_t SetupDDS(void);


#endif /* INC_GENERATE_H_ */
