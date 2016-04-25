// PowerScreenShot.h: interface for the PowerScreenShot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POWERSCREENSHOT_H__ED178596_704F_4C87_8EED_FC66B58B1937__INCLUDED_)
#define AFX_POWERSCREENSHOT_H__ED178596_704F_4C87_8EED_FC66B58B1937__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#include "Command.h"

#include <vector>
#include <string>
using namespace std;
class PowerScreenShot  
{
private:
	int currentStat;
	vector<Command*> commandList;
public:
	void remove();
	void cancel();
	void commit();
	void begin();
	void reportCommands();
	void clearCommands();
	int onKey(int keyValue);
	PowerScreenShot();
	virtual ~PowerScreenShot();

};

#endif // !defined(AFX_POWERSCREENSHOT_H__ED178596_704F_4C87_8EED_FC66B58B1937__INCLUDED_)
