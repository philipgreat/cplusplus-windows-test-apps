// SerialPortTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
int showMessage(char *message){
	
	return ::MessageBox(NULL,message,"error",MB_OK);

}
int main(int argc, char* argv[])
{
	HANDLE hSerial = CreateFile("COM1:", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if(hSerial == NULL)
	{
		///L"串口打开失败";
		showMessage("串口打开失败");
		return 0;
	}
	
	///配置串口
	
	DCB PortDCB;
	PortDCB.DCBlength = sizeof(DCB);
	// 默认串口参数
	GetCommState(hSerial, &PortDCB);
	PortDCB.BaudRate = 38400; // baud
	PortDCB.ByteSize = 8; // Number of bits/byte, 4-8
	PortDCB.Parity = NOPARITY;
	PortDCB.StopBits = ONESTOPBIT;
	if (! SetCommState(hSerial, &PortDCB))
	{
		///L"配置串口失败";
		showMessage("配置串口失败");
		return 0;
	}
	
	////配置超时值
	
	COMMTIMEOUTS CommTimeouts;
	
	GetCommTimeouts(hSerial, &CommTimeouts);
	CommTimeouts.ReadIntervalTimeout = MAXDWORD;
	CommTimeouts.ReadTotalTimeoutMultiplier = 10;
	CommTimeouts.ReadTotalTimeoutConstant = 10;
	CommTimeouts.WriteTotalTimeoutMultiplier = 50;
	CommTimeouts.WriteTotalTimeoutConstant = 100;
	if (!SetCommTimeouts(hSerial, &CommTimeouts))
	{
		///L"不能设置超时参数";
		showMessage("不能设置超时参数");
		return 0;
	}
	DWORD ret;
	WriteFile(hSerial,"test1",6,&ret,NULL);
	::CloseHandle(hSerial);

	return 0;
}

