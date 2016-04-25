// JVMTestAgent.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include <jni.h>
#include <jvmti.h>
void outputMethod(const char *className,const char *methodName,const char *signature,const char *ret);
void JNICALL MethodEntry(jvmtiEnv *jvmti_env,
            JNIEnv* jni_env,
            jthread thread,
            jmethodID method)
{


	jvmtiError err;
	char *methodName,*signature,*generic;
	err=jvmti_env->GetMethodName( method,&methodName,&signature,&generic);
	if(err!=JVMTI_ERROR_NONE){
		
		return ;
	}
	jclass clazz;
	err=jvmti_env->GetMethodDeclaringClass(method,&clazz);
	if(err!=JVMTI_ERROR_NONE){		
		return ;
	}
	char *clazzsignature,*clazzgeneric;
	err=jvmti_env->GetClassSignature(clazz,&clazzsignature,&clazzgeneric);
	if(err!=JVMTI_ERROR_NONE){		
		return ;
	}
	//printf("call %s.%s\t%s\t%s\n",clazzsignature,methodName,signature,generic);
	//printf("found method call %u\n",method);
	outputMethod(clazzsignature,methodName,signature,generic);

}
void outputReturn(const char *ret)
{
	//printf(ret);
	if(memcmp(ret,"(null)",6)==0){
		printf("void");
		return;
	}
	printf(ret);
}
void outputMethod(const char *className,const char *methodName,const char *signature,const char *ret)
{
	
	char *p=(char*)(ret);
	//outputReturn(ret);

	//printf("call %s\n",className);
	p=(char*)(className+1);
	while(*(p)!=0){	
		if(*p==';'){
			p++;
			continue;
		}
		if(*p=='/'){
			p++;
			putchar('.');
			continue;
		}
		if(*p=='\r'){
			p++;
			continue;
		}
		if(*p=='\n'){
			p++;
			continue;
		}
		putchar(*p);
		p++;
	}
	putchar('.');
	p=(char*)methodName;
	while(*(p)!=0){
		putchar(*p);
		p++;
	}
	p=(char*)signature;
	while(*(p)!=0){
		putchar(*p);
		p++;
	}
	putchar('\n');
	
} 

JNIEXPORT jint JNICALL Agent_OnLoad(JavaVM *vm, char *options, void *reserved){
	//printf("java vm initialized\n");
	jvmtiEnv *jvmti;
	jvmtiError err;	
	(vm)->GetEnv((void**)&jvmti, JVMTI_VERSION_1_0);
	if (jvmti == NULL) {
		printf("java vm initialized: %ld\n",jvmti);
		return 0;  	
	}
	
	jvmtiCapabilities capabilities;

	err = (jvmti)->GetPotentialCapabilities( &capabilities);
	if (err != JVMTI_ERROR_NONE) {
		printf("GetPotentialCapabilities returns: %ld\n",err);
		return 0;   
	}

	if(!capabilities.can_generate_method_entry_events){
		printf("can_generate_method_entry_events: %u\n",capabilities.can_generate_method_entry_events);
		return 0;   
	}	
	
	err = (jvmti)->AddCapabilities(&capabilities);
	if (err != JVMTI_ERROR_NONE) {
		printf("AddCapabilities returns: %ld\n",err);
		return 0;
	}
	err = jvmti->SetEventNotificationMode(JVMTI_ENABLE,JVMTI_EVENT_METHOD_ENTRY, NULL);
	if (err != JVMTI_ERROR_NONE) {
		printf("SetEventNotificationMode JVMTI_EVENT_METHOD_ENTRY returns: %ld\n",err);
		return 0;	
	}
	jvmtiEventCallbacks callbacks;
	memset(&callbacks,0,sizeof(jvmtiEventCallbacks));
	
	callbacks.MethodEntry=&MethodEntry;
	err=jvmti->SetEventCallbacks( &callbacks,sizeof(jvmtiEventCallbacks));
	if (err != JVMTI_ERROR_NONE) {
		printf("SetEventCallbacks returns: %ld\n",err);
		return 0;
	}


#if 0	
	jvmtiPhase phase;
	err=jvmti->GetPhase(&phase);
	if (err != JVMTI_ERROR_NONE) {
		printf("GetPhase returns: %ld\n",err);
		return 0;
	}
	printf("GetPhase returns: %ld\n",phase);
#endif	
	return (jint)0;
}
JNIEXPORT void JNICALL Agent_OnUnload(JavaVM *vm)
{
	//printf("java vm uninitialized\n");

}
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

