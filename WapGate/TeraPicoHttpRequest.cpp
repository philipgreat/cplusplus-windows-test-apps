
#include "TeraPicoHttpRequest.h"

namespace terapico{

CTeraPicoHttpRequest::CTeraPicoHttpRequest()
{

}

CTeraPicoHttpRequest::CTeraPicoHttpRequest(
		long	id,
		pchar	method,
		pchar	query_string)
{

	SetId(id);
	SetMethod(method);
	SetQueryString(query_string);
}


CTeraPicoHttpRequest::~CTeraPicoHttpRequest()
{

}

bool CTeraPicoHttpRequest::Reset(
		pchar	method,
		pchar	query_string)
{
	
	SetMethod(method);
	SetQueryString(query_string);
	return true;
}


void  CTeraPicoHttpRequest::SetId(long id)
{
	this->m_lngId=id;
}
long CTeraPicoHttpRequest::GetId()
{
	return this->m_lngId;
}

void  CTeraPicoHttpRequest::SetMethod(pchar method)
{
	this->m_strMethod=method;
}
pchar CTeraPicoHttpRequest::GetMethod()
{
	return this->m_strMethod;
}

void  CTeraPicoHttpRequest::SetQueryString(pchar query_string)
{
	this->m_strQueryString=query_string;
}
pchar CTeraPicoHttpRequest::GetQueryString()
{
	return this->m_strQueryString;
}


}//end of namespace terapico


