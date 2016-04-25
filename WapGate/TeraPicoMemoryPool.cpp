
#include "TeraPicoMemoryPool.h"

namespace terapico{

CTeraPicoMemoryPool::CTeraPicoMemoryPool()
{

}

CTeraPicoMemoryPool::CTeraPicoMemoryPool(
		long	id,
		pchar	name,
		long	size,
		long	start,
		pchar	chrunk)
{

	SetId(id);
	SetName(name);
	SetSize(size);
	SetStart(start);
	SetChrunk(chrunk);
}


CTeraPicoMemoryPool::~CTeraPicoMemoryPool()
{

}

bool CTeraPicoMemoryPool::Reset(
		pchar	name,
		long	size,
		long	start,
		pchar	chrunk)
{
	
	SetName(name);
	SetSize(size);
	SetStart(start);
	SetChrunk(chrunk);
	return true;
}


void  CTeraPicoMemoryPool::SetId(long id)
{
	this->m_lngId=id;
}
long CTeraPicoMemoryPool::GetId()
{
	return this->m_lngId;
}

void  CTeraPicoMemoryPool::SetName(pchar name)
{
	this->m_strName=name;
}
pchar CTeraPicoMemoryPool::GetName()
{
	return this->m_strName;
}

void  CTeraPicoMemoryPool::SetSize(long size)
{
	this->m_lngSize=size;
}
long CTeraPicoMemoryPool::GetSize()
{
	return this->m_lngSize;
}

void  CTeraPicoMemoryPool::SetStart(long start)
{
	this->m_lngStart=start;
}
long CTeraPicoMemoryPool::GetStart()
{
	return this->m_lngStart;
}

void  CTeraPicoMemoryPool::SetChrunk(pchar chrunk)
{
	this->m_strChrunk=chrunk;
}
pchar CTeraPicoMemoryPool::GetChrunk()
{
	return this->m_strChrunk;
}


}//end of namespace terapico





