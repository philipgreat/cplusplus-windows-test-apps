
#include "TeraPicoHttpHeader.h"

namespace terapico{

CTeraPicoHttpHeader::CTeraPicoHttpHeader()
{

}

CTeraPicoHttpHeader::CTeraPicoHttpHeader(
		long	id,
		pchar	name,
		pchar	value)
{

	SetId(id);
	SetName(name);
	SetValue(value);
}


CTeraPicoHttpHeader::~CTeraPicoHttpHeader()
{

}

bool CTeraPicoHttpHeader::Reset(
		pchar	name,
		pchar	value)
{
	
	SetName(name);
	SetValue(value);
	return true;
}


void  CTeraPicoHttpHeader::SetId(long id)
{
	this->m_lngId=id;
}
long CTeraPicoHttpHeader::GetId()
{
	return this->m_lngId;
}

void  CTeraPicoHttpHeader::SetName(pchar name)
{
	this->m_strName=name;
}
pchar CTeraPicoHttpHeader::GetName()
{
	return this->m_strName;
}

void  CTeraPicoHttpHeader::SetValue(pchar value)
{
	this->m_strValue=value;
}
pchar CTeraPicoHttpHeader::GetValue()
{
	return this->m_strValue;
}


}//end of namespace terapico


