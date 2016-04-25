
#include "TeraPicoBook.h"

namespace terapico{

CTeraPicoBook::CTeraPicoBook()
{

}

CTeraPicoBook::CTeraPicoBook(
		long	id,
		pchar	name,
		pPen	pen)
{

	SetId(id);
	SetName(name);
	SetPen(pen);
}


CTeraPicoBook::~CTeraPicoBook()
{

}

bool CTeraPicoBook::Reset(
		pchar	name,
		pPen	pen)
{
	
	SetName(name);
	SetPen(pen);
	return true;
}


void  CTeraPicoBook::SetId(long id)
{
	this->m_lngId=id;
}
long CTeraPicoBook::GetId()
{
	return this->m_lngId;
}

void  CTeraPicoBook::SetName(pchar name)
{
	this->m_strName=name;
}
pchar CTeraPicoBook::GetName()
{
	return this->m_strName;
}

void  CTeraPicoBook::SetPen(pPen pen)
{
	this->m_objPen=pen;
}
pPen CTeraPicoBook::GetPen()
{
	return this->m_objPen;
}


}//end of namespace terapico


