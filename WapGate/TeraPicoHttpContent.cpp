
#include "TeraPicoHttpContent.h"

namespace terapico{

CTeraPicoHttpContent::CTeraPicoHttpContent()
{

}

CTeraPicoHttpContent::CTeraPicoHttpContent(
		long	id,
		pHttpHeader	request,
		pHttpBody	content_body)
{

	SetId(id);
	SetRequest(request);
	SetContentBody(content_body);
}


CTeraPicoHttpContent::~CTeraPicoHttpContent()
{

}

bool CTeraPicoHttpContent::Reset(
		pHttpHeader	request,
		pHttpBody	content_body)
{
	
	SetRequest(request);
	SetContentBody(content_body);
	return true;
}


void  CTeraPicoHttpContent::SetId(long id)
{
	this->m_lngId=id;
}
long CTeraPicoHttpContent::GetId()
{
	return this->m_lngId;
}

void  CTeraPicoHttpContent::SetRequest(pHttpHeader request)
{
	this->m_objRequest=request;
}
pHttpHeader CTeraPicoHttpContent::GetRequest()
{
	return this->m_objRequest;
}

void  CTeraPicoHttpContent::SetContentBody(pHttpBody content_body)
{
	this->m_objContentBody=content_body;
}
pHttpBody CTeraPicoHttpContent::GetContentBody()
{
	return this->m_objContentBody;
}


}//end of namespace terapico


