
#ifndef  TERA_PICO_MEMORY_POOL_ClASS
#define  TERA_PICO_MEMORY_POOL_ClASS
#include "TeraPicoCommon.h"

namespace terapico{

class CTeraPicoMemoryPool
{
private:
	
	long	m_lngId;
	pchar	m_strName;
	long	m_lngSize;
	long	m_lngStart;
	pchar	m_strChrunk;
	
	
public:

	CTeraPicoMemoryPool();
	CTeraPicoMemoryPool(
		long	id,
		pchar	name,
		long	size,
		long	start,
		pchar	chrunk);
	virtual ~CTeraPicoMemoryPool();

	bool Reset(
		pchar	name,
		long	size,
		long	start,
		pchar	chrunk);
	
	long GetId();
	void SetId(long id);
	
	pchar GetName();
	void SetName(pchar name);
	
	long GetSize();
	void SetSize(long size);
	
	long GetStart();
	void SetStart(long start);
	
	pchar GetChrunk();
	void SetChrunk(pchar chrunk);
	

};//end of  class CTeraPicoMemoryPool

typedef CTeraPicoMemoryPool* pMemoryPool;
typedef CTeraPicoMemoryPool MemoryPool;

}//end of namespace terapico

#endif //TERA_PICO_MEMORY_POOL_ClASS




