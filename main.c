
/*
 * main.c
 *
 *  Created on: 19 Dec 2019
 *      Author: amin
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Local.h"
#include "DIO_config.h"
#include "DIO.h"
#include "delay.h"
#include "UART.h"
#include "WiMOD_LoRaWAN_API.h"

//Device EUI:
unsigned char DeviceEUI[8] ={0x35,0xff,0xa9,0x55,0x34,0xa4,0x1d,0xcf} ;

//Device address:
unsigned char DeviceAddress[4] ={ 0xe2 , 0x16 , 0x6e , 0x01 };

//Application session key (LoRaWAN 1.0):
unsigned char ApplicationSessionKey[16] = { 0xee, 0xf1, 0xbb, 0x14, 0x3e, 0x25, 0x60, 0x4f, 0xf8, 0xa8, 0x86, 0x09, 0x33, 0x28, 0x2c, 0xa2 }  ;

//Network session key (LoRaWAN 1.0):
unsigned char NetworkSessionKey[16] = { 0xbf, 0x36, 0xd1, 0xfa, 0xb8, 0x9c, 0x84, 0x1d, 0x74, 0xae, 0x03, 0xc3, 0xa0, 0x58, 0xdc, 0xde } ;



int main()

{
	WiMOD_LoRaWAN_Init();
	WiMOD_LoRaWAN_ABP_Activate(DeviceAddress , NetworkSessionKey , ApplicationSessionKey);

	char Txtmessage_lora_str[]="RaNna_Reda_";
	int i=0;
	while(1)
	{
		i++;
		Txtmessage_lora_str[11]=i/100+'0';
		Txtmessage_lora_str[12]=((i%100)/10)+'0';
		Txtmessage_lora_str[13]=(i%10)+'0';
		Txtmessage_lora_str[14]='\0';
		delay_ms(10000);
	}
	WiMOD_LoRaWAN_SendPing();
	WiMOD_LoRaWAN_SendURadioData(0x22, Txtmessage_lora_str, 14);
	return 0;
}
