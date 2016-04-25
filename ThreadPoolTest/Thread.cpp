// Thread.cpp: implementation of the Thread class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Thread.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


static enum {
	THREAD_STATE_INITIATED=0,
	THREAD_STATE_ACTIVED,
	THREAD_STATE_PASSIVED,
	THREAD_STATE_RUNNING,
	THREAD_STATE_RAN,
	THREAD_STATE_DEAD,
};

static DWORD __stdcall ThreadWork(void *pTask)
{	
	Thread *p=(Thread*)pTask;
	while(1){
		p->start();
		p->run();
		p->end();
		p->passive();
		//stop when executed the task;
		//and wait for another active
	}
	return 0;
}


Thread::Thread()
{
	//printf("thread initiated\n");	
	threadHandle=::CreateThread(
		NULL,
		40*1024,
		ThreadWork,
		(void*)this,
		CREATE_SUSPENDED,
		&this->threadId);
	this->threadState = THREAD_STATE_INITIATED;

}


Thread::~Thread()
{
	//printf("try to close the thread\n");
	CloseHandle(this->threadHandle);
	this->threadState = THREAD_STATE_DEAD;

}

void Thread::SetId(int id)
{
	threadId= id;	
}

void Thread::run()
{
	printf("runtask in thread %u\n",this->threadId);
	this->threadState = THREAD_STATE_RUNNING;
	if(NULL!=this->currentTask){
		this->currentTask->execute();	
	}
	this->currentTask = NULL;
	this->threadState = THREAD_STATE_RAN;

}

void Thread::end()
{
	//printf("end called\n");
}

void Thread::start()
{
	//printf("end called\n");
}


void Thread::active(Task *p)
{
	this->currentTask=p;
	this->threadState = THREAD_STATE_ACTIVED;
	int ret=::ResumeThread(this->threadHandle);
	//printf("thread actived %d\n",ret);
}

void Thread::passive()
{
	this->threadState = THREAD_STATE_PASSIVED;
	int ret=::SuspendThread(this->threadHandle);
	
}


bool Thread::isPassived()
{
	return this->threadState == THREAD_STATE_PASSIVED;
}

bool Thread::canRunNewTask()
{
	return this->threadState == THREAD_STATE_PASSIVED
		||this->threadState == THREAD_STATE_INITIATED;
}

/*

3.1  创建一个线程

      Windows API 调用CreateThread 函数来创建一个线程。函数如下:

HANDLE CreateThread(

LPSECURITY_ATTRIBUTES  lpThreadAttributes,

//线程安全属性地址

DWORD  dwStackSize,

//初始化线程堆栈尺寸

LPTHREAD_START_ROUTINE  lpStartAddress,

//线程函数所指向的地址

LPVOID  lpParameter,

//给线程函数传递的参数

DWORD  dwCreationFlags,

//有关线程的标志

LPDWORD  lpThreadId

//系统分配给线程的ID );

第一个参数是安全属性，一般设为nil，使用缺省的安全属性。当我们想此线程有另外的子进程时，可改变它的属性。

第二个参数是线程堆栈尺寸，一般设为0，表示与此应用的堆栈尺寸相同，即主线程创建的线程一样长度的堆栈。并且其长度会根据需要自动变长。

第三个参数，也是最重要的一个，是一个指向函数名的指针，但传递时很简单，只需在线程函数名前加上@就可以了。

第四个参数是你需要向线程函数传递的参数，一般是一个指向结构的指针。不需传递参数时，则这个参数设为nil。

第五个参数，传入与线程有关的一些标志，如果是CREATE_SUSPENDED，则创建一个挂起的线程，即这个线程本身已创建，
它的堆栈也已创建。但这个线程不会被分配给CPU时间，只有当ResumeThread函数被调用后才能执行；当然，也可以调用SuspendThread函数再次挂起线程。要是标志为0，那么一旦建立线程，线程函数就被立即调用。一般传为0即可。

最后一个参数是系统分配给这个线程的唯一的ID标志。

3.2 终止线程

一般我们可以调用myThread从TThread类继承下来Suspend和Free方法：

TestThread:= TmyThread．Create(False,Query1);

TestThread. Suspend;    //为了安全地关掉线程

TestThread. Free;

      但 TmyThread类中只有Create而没有Free，动态建立类以后又忘记删除是我们常犯的错误之一，不过在这里由于我们指定了FreeOnTerminate(运行完即删除)为真，所以当Execute里的语句执行完后，TmyThread类占据的内存控件将被自动释放。

 3.3 设定线程的相对优先级

         当一个线程被首次创建时，它的优先级等同于它所属进程的优先级。在单个进程内可以通过调用SetThreadPriority函数改变线程的相对优先级。一个线程的优先级是相对于其所属的进程的优先级而言的。

           SetThreadPriority( HANDLE  hThread, int  nPriority )： BOOL;

        其中参数hThread是指向待修改优先级线程的句柄，nPriority可以是以下的值:

THREAD_PRIORITY_LOWEST，

THREAD_PRIORITY_BELOW_NORMAL，

THREAD_PRIORITY_NORMAL，

THREAD_PRIORITY_ABOVE_NORMAL，

THREAD_PRIORITY_HGHEST

 3.4 挂起及恢复线程

    我们可以调用myThread从TThread类继承下来Suspend方法挂起线程和Resume方法恢复线程：

TestThread. Suspend;

TestThread. Resume;

同时也可以通过设置Suspended属性：

TestThread. Suspended：＝True;       //挂起

TestThread. Suspended：＝False; //恢复


*/
