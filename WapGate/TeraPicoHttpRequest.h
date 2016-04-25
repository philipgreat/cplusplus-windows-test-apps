
#ifndef  TERA_PICO_HTTP_REQUEST_ClASS
#define  TERA_PICO_HTTP_REQUEST_ClASS
#include "TeraPicoCommon.h"

#include "TeraPicoHttpHeader.h"
	
namespace terapico{

class CTeraPicoHttpRequest
{
private:
	
	long	m_lngId;
	pchar	m_strMethod;
	pchar	m_strQueryString;
	
	list<HttpHeader*> m_listHttpHeaders;
	
public:

	CTeraPicoHttpRequest();
	CTeraPicoHttpRequest(
		long	id,
		pchar	method,
		pchar	query_string);
	virtual ~CTeraPicoHttpRequest();

	bool Reset(
		pchar	method,
		pchar	query_string);
	
	long GetId();
	void SetId(long id);
	
	pchar GetMethod();
	void SetMethod(pchar method);
	
	pchar GetQueryString();
	void SetQueryString(pchar query_string);
	
	list<HttpHeader*> GetHttpHeaders()
	{
		return m_listHttpHeaders;
	}
	void AddHttpHeader(HttpHeader* header){
		m_listHttpHeaders.push_back(header);
	}
	void RemoveAllHttpHeaders(){
		m_listHttpHeaders.clear();
	}
	void RemoveHttpHeader(long id){
		list<HttpHeader*>::iterator new_end	= remove_if(
				m_listHttpHeaders.begin(),
				m_listHttpHeaders.end(),
				FindById<HttpHeader>(id));
		m_listHttpHeaders.erase(new_end,m_listHttpHeaders.end());
	}

	void ListHttpHeaders(){
		for (
			list<HttpHeader*>::const_iterator it =m_listHttpHeaders.begin();
			it != m_listHttpHeaders.end();
			++it
		){
			printf("the HttpHeader id: %d\n",(*it)->GetId ());
		}
	}

	

};//end of  class CTeraPicoHttpRequest

typedef CTeraPicoHttpRequest* pHttpRequest;
typedef CTeraPicoHttpRequest HttpRequest;

}//end of namespace terapico

#endif //TERA_PICO_HTTP_REQUEST_ClASS


