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
		///L"���ڴ�ʧ��";
		showMessage("���ڴ�ʧ��");
		return 0;
	}
	
	///���ô���
	
	DCB PortDCB;
	PortDCB.DCBlength = sizeof(DCB);
	// Ĭ�ϴ��ڲ���
	GetCommState(hSerial, &PortDCB);
	PortDCB.BaudRate = 38400; // baud
	PortDCB.ByteSize = 8; // Number of bits/byte, 4-8
	PortDCB.Parity = NOPARITY;
	PortDCB.StopBits = ONESTOPBIT;
	if (! SetCommState(hSerial, &PortDCB))
	{
		///L"���ô���ʧ��";
		showMessage("���ô���ʧ��");
		return 0;
	}
	
	////���ó�ʱֵ
	
	COMMTIMEOUTS CommTimeouts;
	
	GetCommTimeouts(hSerial, &CommTimeouts);
	CommTimeouts.ReadIntervalTimeout = MAXDWORD;
	CommTimeouts.ReadTotalTimeoutMultiplier = 10;
	CommTimeouts.ReadTotalTimeoutConstant = 10;
	CommTimeouts.WriteTotalTimeoutMultiplier = 50;
	CommTimeouts.WriteTotalTimeoutConstant = 100;
	if (!SetCommTimeouts(hSerial, &CommTimeouts))
	{
		///L"�������ó�ʱ����";
		showMessage("�������ó�ʱ����");
		return 0;
	}
	DWORD ret;
	WriteFile(hSerial,"test1",6,&ret,NULL);
	::CloseHandle(hSerial);

	return 0;
}

