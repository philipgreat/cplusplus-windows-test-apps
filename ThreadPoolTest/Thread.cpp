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

3.1  ����һ���߳�

      Windows API ����CreateThread ����������һ���̡߳���������:

HANDLE CreateThread(

LPSECURITY_ATTRIBUTES  lpThreadAttributes,

//�̰߳�ȫ���Ե�ַ

DWORD  dwStackSize,

//��ʼ���̶߳�ջ�ߴ�

LPTHREAD_START_ROUTINE  lpStartAddress,

//�̺߳�����ָ��ĵ�ַ

LPVOID  lpParameter,

//���̺߳������ݵĲ���

DWORD  dwCreationFlags,

//�й��̵߳ı�־

LPDWORD  lpThreadId

//ϵͳ������̵߳�ID );

��һ�������ǰ�ȫ���ԣ�һ����Ϊnil��ʹ��ȱʡ�İ�ȫ���ԡ�����������߳���������ӽ���ʱ���ɸı��������ԡ�

�ڶ����������̶߳�ջ�ߴ磬һ����Ϊ0����ʾ���Ӧ�õĶ�ջ�ߴ���ͬ�������̴߳������߳�һ�����ȵĶ�ջ�������䳤�Ȼ������Ҫ�Զ��䳤��

������������Ҳ������Ҫ��һ������һ��ָ��������ָ�룬������ʱ�ܼ򵥣�ֻ�����̺߳�����ǰ����@�Ϳ����ˡ�

���ĸ�����������Ҫ���̺߳������ݵĲ�����һ����һ��ָ��ṹ��ָ�롣���贫�ݲ���ʱ�������������Ϊnil��

������������������߳��йص�һЩ��־�������CREATE_SUSPENDED���򴴽�һ��������̣߳�������̱߳����Ѵ�����
���Ķ�ջҲ�Ѵ�����������̲߳��ᱻ�����CPUʱ�䣬ֻ�е�ResumeThread���������ú����ִ�У���Ȼ��Ҳ���Ե���SuspendThread�����ٴι����̡߳�Ҫ�Ǳ�־Ϊ0����ôһ�������̣߳��̺߳����ͱ��������á�һ�㴫Ϊ0���ɡ�

���һ��������ϵͳ���������̵߳�Ψһ��ID��־��

3.2 ��ֹ�߳�

һ�����ǿ��Ե���myThread��TThread��̳�����Suspend��Free������

TestThread:= TmyThread��Create(False,Query1);

TestThread. Suspend;    //Ϊ�˰�ȫ�عص��߳�

TestThread. Free;

      �� TmyThread����ֻ��Create��û��Free����̬�������Ժ�������ɾ�������ǳ����Ĵ���֮һ��������������������ָ����FreeOnTerminate(�����꼴ɾ��)Ϊ�棬���Ե�Execute������ִ�����TmyThread��ռ�ݵ��ڴ�ؼ������Զ��ͷš�

 3.3 �趨�̵߳�������ȼ�

         ��һ���̱߳��״δ���ʱ���������ȼ���ͬ�����������̵����ȼ����ڵ��������ڿ���ͨ������SetThreadPriority�����ı��̵߳�������ȼ���һ���̵߳����ȼ���������������Ľ��̵����ȼ����Եġ�

           SetThreadPriority( HANDLE  hThread, int  nPriority )�� BOOL;

        ���в���hThread��ָ����޸����ȼ��̵߳ľ����nPriority���������µ�ֵ:

THREAD_PRIORITY_LOWEST��

THREAD_PRIORITY_BELOW_NORMAL��

THREAD_PRIORITY_NORMAL��

THREAD_PRIORITY_ABOVE_NORMAL��

THREAD_PRIORITY_HGHEST

 3.4 ���𼰻ָ��߳�

    ���ǿ��Ե���myThread��TThread��̳�����Suspend���������̺߳�Resume�����ָ��̣߳�

TestThread. Suspend;

TestThread. Resume;

ͬʱҲ����ͨ������Suspended���ԣ�

TestThread. Suspended����True;       //����

TestThread. Suspended����False; //�ָ�


*/
