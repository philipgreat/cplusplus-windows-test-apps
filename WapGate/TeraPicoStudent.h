
#ifndef  TERA_PICO_STUDENT_ClASS
#define  TERA_PICO_STUDENT_ClASS
#include "TeraPicoCommon.h"

#include "TeraPicoBook.h"
	
#include "TeraPicoPen.h"
	
namespace terapico{

class CTeraPicoStudent
{
private:
	
	long	m_lngId;
	pchar	m_strName;
	double	m_dblAge;
	
	list<Book*> m_listBooks;
	list<Pen*> m_listPens;
	
public:

	CTeraPicoStudent();
	CTeraPicoStudent(
		long	id,
		pchar	name,
		double	age);
	virtual ~CTeraPicoStudent();

	bool Reset(
		pchar	name,
		double	age);
	
	long GetId();
	void SetId(long id);
	
	pchar GetName();
	void SetName(pchar name);
	
	double GetAge();
	void SetAge(double age);
	
	list<Book*> GetBooks()
	{
		return m_listBooks;
	}
	void AddBook(Book* owner){
		m_listBooks.push_back(owner);
	}
	void RemoveAllBooks(){
		m_listBooks.clear();
	}
	void RemoveBook(long id){
		list<Book*>::iterator new_end = remove_if(
				m_listBooks.begin(),
				m_listBooks.end(),
				FindById<Book>(id));
		m_listBooks.erase(new_end,m_listBooks.end());
	}

	void ListBooks(){
		for (
			list<Book*>::const_iterator it =m_listBooks.begin();
			it != m_listBooks.end();
			++it
		){
			printf("the Book id: %d\n",(*it)->GetId ());
		}
	}

	
	list<Pen*> GetPens()
	{
		return m_listPens;
	}
	void AddPen(Pen* owner){
		m_listPens.push_back(owner);
	}
	void RemoveAllPens(){
		m_listPens.clear();
	}
	void RemovePen(long id){
		list<Pen*>::iterator new_end = remove_if(
				m_listPens.begin(),
				m_listPens.end(),
				FindById<Pen>(id));
		m_listPens.erase(new_end,m_listPens.end());
	}

	void ListPens(){
		for (
			list<Pen*>::const_iterator it =m_listPens.begin();
			it != m_listPens.end();
			++it
		){
			printf("the Pen id: %d\n",(*it)->GetId ());
		}
	}

	

};//end of  class CTeraPicoStudent

typedef CTeraPicoStudent* pStudent;
typedef CTeraPicoStudent Student;

}//end of namespace terapico

#endif //TERA_PICO_STUDENT_ClASS


