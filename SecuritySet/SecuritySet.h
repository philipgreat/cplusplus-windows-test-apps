/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Jan 14 19:04:52 2007
 */
/* Compiler settings for F:\suddy\vc\SecuritySet\SecuritySet.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __SecuritySet_h__
#define __SecuritySet_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IHaspKey_FWD_DEFINED__
#define __IHaspKey_FWD_DEFINED__
typedef interface IHaspKey IHaspKey;
#endif 	/* __IHaspKey_FWD_DEFINED__ */


#ifndef __HaspKey_FWD_DEFINED__
#define __HaspKey_FWD_DEFINED__

#ifdef __cplusplus
typedef class HaspKey HaspKey;
#else
typedef struct HaspKey HaspKey;
#endif /* __cplusplus */

#endif 	/* __HaspKey_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IHaspKey_INTERFACE_DEFINED__
#define __IHaspKey_INTERFACE_DEFINED__

/* interface IHaspKey */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IHaspKey;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A31FF10C-B204-4231-885B-621F0CC19924")
    IHaspKey : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE login( 
            /* [in] */ BSTR url,
            /* [in] */ BSTR username,
            /* [in] */ BSTR password,
            /* [out][retval] */ BSTR __RPC_FAR *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE applyToken( 
            /* [in] */ BSTR url,
            /* [in] */ BSTR cookie,
            /* [retval][out] */ BSTR __RPC_FAR *result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHaspKeyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IHaspKey __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IHaspKey __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IHaspKey __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IHaspKey __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IHaspKey __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IHaspKey __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IHaspKey __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *login )( 
            IHaspKey __RPC_FAR * This,
            /* [in] */ BSTR url,
            /* [in] */ BSTR username,
            /* [in] */ BSTR password,
            /* [out][retval] */ BSTR __RPC_FAR *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *applyToken )( 
            IHaspKey __RPC_FAR * This,
            /* [in] */ BSTR url,
            /* [in] */ BSTR cookie,
            /* [retval][out] */ BSTR __RPC_FAR *result);
        
        END_INTERFACE
    } IHaspKeyVtbl;

    interface IHaspKey
    {
        CONST_VTBL struct IHaspKeyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHaspKey_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHaspKey_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHaspKey_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHaspKey_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IHaspKey_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IHaspKey_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IHaspKey_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IHaspKey_login(This,url,username,password,result)	\
    (This)->lpVtbl -> login(This,url,username,password,result)

#define IHaspKey_applyToken(This,url,cookie,result)	\
    (This)->lpVtbl -> applyToken(This,url,cookie,result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHaspKey_login_Proxy( 
    IHaspKey __RPC_FAR * This,
    /* [in] */ BSTR url,
    /* [in] */ BSTR username,
    /* [in] */ BSTR password,
    /* [out][retval] */ BSTR __RPC_FAR *result);


void __RPC_STUB IHaspKey_login_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHaspKey_applyToken_Proxy( 
    IHaspKey __RPC_FAR * This,
    /* [in] */ BSTR url,
    /* [in] */ BSTR cookie,
    /* [retval][out] */ BSTR __RPC_FAR *result);


void __RPC_STUB IHaspKey_applyToken_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHaspKey_INTERFACE_DEFINED__ */



#ifndef __SECURITYSETLib_LIBRARY_DEFINED__
#define __SECURITYSETLib_LIBRARY_DEFINED__

/* library SECURITYSETLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SECURITYSETLib;

EXTERN_C const CLSID CLSID_HaspKey;

#ifdef __cplusplus

class DECLSPEC_UUID("CCD223DE-B3FB-4F5A-BB71-5268E2FCB4AB")
HaspKey;
#endif
#endif /* __SECURITYSETLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
