
#include "TeraPicoHttpBody.h"

namespace terapico{

CTeraPicoHttpBody::CTeraPicoHttpBody()
{

}

CTeraPicoHttpBody::CTeraPicoHttpBody(
		long	id,
		pchar	content,
		long	length)
{

	SetId(id);
	SetContent(content);
	SetLength(length);
}


CTeraPicoHttpBody::~CTeraPicoHttpBody()
{

}

bool CTeraPicoHttpBody::Reset(
		pchar	content,
		long	length)
{
	
	SetContent(content);
	SetLength(length);
	return true;
}


void  CTeraPicoHttpBody::SetId(long id)
{
	this->m_lngId=id;
}
long CTeraPicoHttpBody::GetId()
{
	return this->m_lngId;
}

void  CTeraPicoHttpBody::SetContent(pchar content)
{
	this->m_strContent=content;
}
pchar CTeraPicoHttpBody::GetContent()
{
	return this->m_strContent;
}

void  CTeraPicoHttpBody::SetLength(long length)
{
	this->m_lngLength=length;
}
long CTeraPicoHttpBody::GetLength()
{
	return this->m_lngLength;
}


}//end of namespace terapico


