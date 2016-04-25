
#include "TeraPicoStudent.h"

namespace terapico{

CTeraPicoStudent::CTeraPicoStudent()
{

}

CTeraPicoStudent::CTeraPicoStudent(
		long	id,
		pchar	name,
		double	age)
{

	SetId(id);
	SetName(name);
	SetAge(age);
}


CTeraPicoStudent::~CTeraPicoStudent()
{

}

bool CTeraPicoStudent::Reset(
		pchar	name,
		double	age)
{
	
	SetName(name);
	SetAge(age);
	return true;
}


void  CTeraPicoStudent::SetId(long id)
{
	this->m_lngId=id;
}
long CTeraPicoStudent::GetId()
{
	return this->m_lngId;
}

void  CTeraPicoStudent::SetName(pchar name)
{
	this->m_strName=name;
}
pchar CTeraPicoStudent::GetName()
{
	return this->m_strName;
}

void  CTeraPicoStudent::SetAge(double age)
{
	this->m_dblAge=age;
}
double CTeraPicoStudent::GetAge()
{
	return this->m_dblAge;
}


}//end of namespace terapico


