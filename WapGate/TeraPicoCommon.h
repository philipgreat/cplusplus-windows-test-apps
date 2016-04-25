#include <stdlib.h>

#ifndef  TERA_PICO_COMMON_HEADER_ClASS
#define  TERA_PICO_COMMON_HEADER_ClASS
#include <list>
#include <algorithm>
using namespace std;
namespace terapico{
#ifndef WIN32
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#else
#include <windows.h>
#include <process.h>
#include <winsock.h>
#include <io.h>
#endif

#define  WINSOCKET_INIT		WSADATA wsd;\
	if(WSAStartup(MAKEWORD(2,0),&wsd)!=0)\
	{\
		 printf("Socket uninted!");\
	}
#define  WINSOCKET_UNINIT	WSACleanup();

typedef  char*	pchar;
template<class T>class FindById
{
private:
	long m_longId;
public:
	FindById(int id){
		m_longId=id;
	}
public: 
	bool operator()(T* t) const
	{
		//printf("I was called by XXX bk_id=%uL  and the mem_id=%uL \n",bk->GetId(),m_longId);
		return (t->GetId()==m_longId);
	}
};
class CTeraPicoCommonObject{
	virtual long  GetId()=0;
	
};
}//end of namespaceterapico

#endif //TERA_PICO_COMMON_ClASS




