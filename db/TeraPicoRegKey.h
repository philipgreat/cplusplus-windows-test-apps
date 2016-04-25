// TeraPicoRegKey.h: interface for the CTeraPicoRegKey class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(TERA_PICO_REG_KEY_ClASS)
#define TERA_PICO_REG_KEY_ClASS

#define			TERAPICO_KEY_LENGTH		(64)

#include <atlbase.h>

//##ModelId=4095FA7B002E
class CTeraPicoRegKey  
{
private:
	
public:
	//##ModelId=4095FA7B003E
	static bool GetValue(char *key,char *name,char  value[]);
	//##ModelId=4095FA7B0050
	static bool GetValue(char *key, char *name, double &value);
	//##ModelId=4095FA7B006D
	static bool GetValue(char *key, char *name, float &value);
	//##ModelId=4095FA7B007E
	static bool GetValue(char *key, char *name, long &value);
	//##ModelId=4095FA7B008E
	static bool GetValue(char *key ,char *name,int &value);
	//##ModelId=4095FA7B00A0
	static bool SetValue(char *key,char * name,float value);
	//##ModelId=4095FA7B00BB
	static bool SetValue(char *key,char * name,double value);
	//##ModelId=4095FA7B00CD
	static bool SetValue(char *key,char * name,long value);
	//##ModelId=4095FA7B00DD
	static bool SetValue(char *key,char * name,int value);
	//##ModelId=4095FA7B00FA
	static bool SetValue(char * key,char *name, char *value);
	//##ModelId=4095FA7B010A
	CTeraPicoRegKey();
	//##ModelId=4095FA7B010B
	virtual ~CTeraPicoRegKey();

};

#endif // !defined(AFX_TERAPICOREGKEY_H__A3F26720_743B_4298_8337_B3F3FADEC206__INCLUDED_)
