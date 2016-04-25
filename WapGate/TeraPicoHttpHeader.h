
#ifndef  TERA_PICO_HTTP_HEADER_ClASS
#define  TERA_PICO_HTTP_HEADER_ClASS
#include "TeraPicoCommon.h"

namespace terapico{

class CTeraPicoHttpHeader
{
private:
	
	long	m_lngId;
	pchar	m_strName;
	pchar	m_strValue;
	
	
public:

	CTeraPicoHttpHeader();
	CTeraPicoHttpHeader(
		long	id,
		pchar	name,
		pchar	value);
	virtual ~CTeraPicoHttpHeader();

	bool Reset(
		pchar	name,
		pchar	value);
	
	long GetId();
	void SetId(long id);
	
	pchar GetName();
	void SetName(pchar name);
	
	pchar GetValue();
	void SetValue(pchar value);
	

};//end of  class CTeraPicoHttpHeader

typedef CTeraPicoHttpHeader* pHttpHeader;
typedef CTeraPicoHttpHeader HttpHeader;

}//end of namespace terapico

#endif //TERA_PICO_HTTP_HEADER_ClASS


