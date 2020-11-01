/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : generate.c
  * @brief          : Generates wave.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) Scott Hanson.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "generate.h"
/**
  * @brief  function declarations.
  */

/**
  * @brief  Sends instructions to AD9834 DDS.
  * @retval int
  */
uint8_t GenerateWave(struct Parameters SignalParameters)
{
	uint8_t retval=0;
	extern SPI_HandleTypeDef hspi2;	//the DDS
	extern DAC_HandleTypeDef hdac1;	//wave offset


	uint16_t SendWord=0;	//stores word we will send to the DDS
	uint32_t FreqRegFull=0;
	uint16_t FreqRegLSB=0;
	uint16_t FreqRegMSB=0;
	uint32_t DAC_OUT[4] = {0, 1241, 2482, 3723};

	//value for the frequency register, freqReg=(Fout*2^28)/Fmclk. From AN-1070, page 3
	FreqRegFull=(SignalParameters.Frequency*FREQUENCY_MODIFIER)/FREQ_CLOCK;	//TODO confirm that this doesn't fall foul of uint16_t constraint
	FreqRegLSB=(FreqRegFull&0xFF);
	FreqRegMSB=((FreqRegFull>>16)&0xFF);

	//Offset to be sent to the onboard DAC1 (P3, right hand 3pin header)

	//Amplitude to be sent to the onboard DAC2(P4, left hand 3pin header)



	//TODO set up control register depending on wavetype etc selected; for now, basic wave hardcoded.
	SendWord|=DDS_CTRL_B28|DDS_CTRL_RST|DDS_CTRL_SIGN;
	HAL_GPIO_WritePin(DDS_CS_Port,DDS_CS_Pin,GPIO_PIN_RESET);//CS goes low
	retval=HAL_SPI_Transmit(&hspi2,  SendWord, 2, 100);
	HAL_GPIO_WritePin(DDS_CS_Port,DDS_CS_Pin,GPIO_PIN_SET);//CS goes high, end of transmission
	SendWord=0;		//clear ready for reuse

	if(!retval)	//continue
	{
		SendWord|=DDS_FREQ0|FreqRegLSB;
		HAL_GPIO_WritePin(DDS_CS_Port,DDS_CS_Pin,GPIO_PIN_RESET);//CS goes low
		retval=HAL_SPI_Transmit(&hspi2,  SendWord, 2, 100);
		HAL_GPIO_WritePin(DDS_CS_Port,DDS_CS_Pin,GPIO_PIN_SET);//CS goes high, end of transmission
		SendWord=0;		//clear ready for reuse
	}
	if(!retval)	//continue
	{
		SendWord|=DDS_FREQ0|FreqRegMSB;
		HAL_GPIO_WritePin(DDS_CS_Port,DDS_CS_Pin,GPIO_PIN_RESET);//CS goes low
		retval=HAL_SPI_Transmit(&hspi2,  SendWord, 2, 100);
		HAL_GPIO_WritePin(DDS_CS_Port,DDS_CS_Pin,GPIO_PIN_SET);//CS goes high, end of transmission
		SendWord=0;		//clear ready for reuse
	}
	if(!retval)	//continue
	{
		SendWord|=DDS_CTRL_B28|DDS_CTRL_SIGN;	//turn off RESET, allow wave to be output
		HAL_GPIO_WritePin(DDS_CS_Port,DDS_CS_Pin,GPIO_PIN_RESET);//CS goes low
		retval=HAL_SPI_Transmit(&hspi2,  SendWord, 2, 100);
		HAL_GPIO_WritePin(DDS_CS_Port,DDS_CS_Pin,GPIO_PIN_SET);//CS goes high, end of transmission
		//Note: it looks as though OPBITEN should only ever be high if I actively want a square wave output.
	}
	/*
	 * This code is working; have removed it so that i can trace the signal path from the DDS chip.
	if(!retval)	//continue
	{
		for (int i=0;i<4;i++)
		{
			DAC1->DHR12R1 = DAC_OUT[i];//results in a nice stepped sawtooth pattern.
		}
		DAC1->DHR12R1 = 0;
	}
	*/
	return retval;
}

/**
  * @brief  Sets control registers of the AD9834 DDS.
  * @retval int
  */
uint8_t SetupDDS(void)
{
	uint8_t retval=0;
	extern SPI_HandleTypeDef hspi2;
	uint16_t SendWord=0;	//the word we will send to the DDS
	//the first two bits, DDS_CTRL_SEL1 and DDS_CTRL_SEL2 need to be 0 for the DDS to accept a control word.

	SendWord|=DDS_CTRL_B28|DDS_CTRL_RST|DDS_CTRL_SIGN;
	HAL_GPIO_WritePin(DDS_CS_Port,DDS_CS_Pin,GPIO_PIN_RESET);//CS goes low
	retval=HAL_SPI_Transmit(&hspi2,  SendWord, 2, 100);
	HAL_GPIO_WritePin(DDS_CS_Port,DDS_CS_Pin,GPIO_PIN_SET);//CS goes high, end of transmission
	return retval;
}
