
#ifndef  TERA_PICO_HTTP_CONTENT_ClASS
#define  TERA_PICO_HTTP_CONTENT_ClASS
#include "TeraPicoCommon.h"

#include "TeraPicoHttpHeader.h"
	
#include "TeraPicoHttpBody.h"
	
namespace terapico{

class CTeraPicoHttpContent
{
private:
	
	long	m_lngId;
	pHttpHeader	m_objRequest;
	pHttpBody	m_objContentBody;
	
	
public:

	CTeraPicoHttpContent();
	CTeraPicoHttpContent(
		long	id,
		pHttpHeader	request,
		pHttpBody	content_body);
	virtual ~CTeraPicoHttpContent();

	bool Reset(
		pHttpHeader	request,
		pHttpBody	content_body);
	
	long GetId();
	void SetId(long id);
	
	pHttpHeader GetRequest();
	void SetRequest(pHttpHeader request);
	
	pHttpBody GetContentBody();
	void SetContentBody(pHttpBody content_body);
	

};//end of  class CTeraPicoHttpContent

typedef CTeraPicoHttpContent* pHttpContent;
typedef CTeraPicoHttpContent HttpContent;

}//end of namespace terapico

#endif //TERA_PICO_HTTP_CONTENT_ClASS


