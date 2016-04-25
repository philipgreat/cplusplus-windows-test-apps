
#ifndef  TERA_PICO_BOOK_ClASS
#define  TERA_PICO_BOOK_ClASS
#include "TeraPicoCommon.h"

#include "TeraPicoPen.h"
	
namespace terapico{

class CTeraPicoBook
{
private:
	
	long	m_lngId;
	pchar	m_strName;
	pPen	m_objPen;
	
	
public:

	CTeraPicoBook();
	CTeraPicoBook(
		long	id,
		pchar	name,
		pPen	pen);
	virtual ~CTeraPicoBook();

	bool Reset(
		pchar	name,
		pPen	pen);
	
	long GetId();
	void SetId(long id);
	
	pchar GetName();
	void SetName(pchar name);
	
	pPen GetPen();
	void SetPen(pPen pen);
	

};//end of  class CTeraPicoBook

typedef CTeraPicoBook* pBook;
typedef CTeraPicoBook Book;

}//end of namespace terapico

#endif //TERA_PICO_BOOK_ClASS


