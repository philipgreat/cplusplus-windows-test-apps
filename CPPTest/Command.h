// Command.h: interface for the Command class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMAND_H__9870CC1A_0AA5_44F6_8615_8C20A7AD8F70__INCLUDED_)
#define AFX_COMMAND_H__9870CC1A_0AA5_44F6_8615_8C20A7AD8F70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Command  
{
private:
	int x;
	int y;
	char cmd;
public:
	void show();
	static Command * getInstance(char cmd);
	Command();
	Command(char command);
	virtual ~Command();

};

#endif // !defined(AFX_COMMAND_H__9870CC1A_0AA5_44F6_8615_8C20A7AD8F70__INCLUDED_)
