
#ifndef  TERA_PICO_HTTP_BODY_ClASS
#define  TERA_PICO_HTTP_BODY_ClASS
#include "TeraPicoCommon.h"

namespace terapico{

class CTeraPicoHttpBody
{
private:
	
	long	m_lngId;
	pchar	m_strContent;
	long	m_lngLength;
	
	
public:

	CTeraPicoHttpBody();
	CTeraPicoHttpBody(
		long	id,
		pchar	content,
		long	length);
	virtual ~CTeraPicoHttpBody();

	bool Reset(
		pchar	content,
		long	length);
	
	long GetId();
	void SetId(long id);
	
	pchar GetContent();
	void SetContent(pchar content);
	
	long GetLength();
	void SetLength(long length);
	

};//end of  class CTeraPicoHttpBody

typedef CTeraPicoHttpBody* pHttpBody;
typedef CTeraPicoHttpBody HttpBody;

}//end of namespace terapico

#endif //TERA_PICO_HTTP_BODY_ClASS


