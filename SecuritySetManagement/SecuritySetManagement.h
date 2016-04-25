/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Jan 12 22:22:40 2007
 */
/* Compiler settings for F:\suddy\vc\SecuritySetManagement\SecuritySetManagement.idl:
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

#ifndef __SecuritySetManagement_h__
#define __SecuritySetManagement_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IIssuer_FWD_DEFINED__
#define __IIssuer_FWD_DEFINED__
typedef interface IIssuer IIssuer;
#endif 	/* __IIssuer_FWD_DEFINED__ */


#ifndef __Issuer_FWD_DEFINED__
#define __Issuer_FWD_DEFINED__

#ifdef __cplusplus
typedef class Issuer Issuer;
#else
typedef struct Issuer Issuer;
#endif /* __cplusplus */

#endif 	/* __Issuer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IIssuer_INTERFACE_DEFINED__
#define __IIssuer_INTERFACE_DEFINED__

/* interface IIssuer */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIssuer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("55C89FF3-1EF0-4675-912C-B8242A00DC18")
    IIssuer : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE issue( 
            /* [in] */ BSTR url,
            /* [in] */ BSTR username,
            /* [in] */ BSTR password,
            /* [retval][out] */ BSTR __RPC_FAR *result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIssuerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIssuer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIssuer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIssuer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IIssuer __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IIssuer __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IIssuer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IIssuer __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *issue )( 
            IIssuer __RPC_FAR * This,
            /* [in] */ BSTR url,
            /* [in] */ BSTR username,
            /* [in] */ BSTR password,
            /* [retval][out] */ BSTR __RPC_FAR *result);
        
        END_INTERFACE
    } IIssuerVtbl;

    interface IIssuer
    {
        CONST_VTBL struct IIssuerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIssuer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIssuer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIssuer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIssuer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IIssuer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IIssuer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IIssuer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IIssuer_issue(This,url,username,password,result)	\
    (This)->lpVtbl -> issue(This,url,username,password,result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIssuer_issue_Proxy( 
    IIssuer __RPC_FAR * This,
    /* [in] */ BSTR url,
    /* [in] */ BSTR username,
    /* [in] */ BSTR password,
    /* [retval][out] */ BSTR __RPC_FAR *result);


void __RPC_STUB IIssuer_issue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIssuer_INTERFACE_DEFINED__ */



#ifndef __SECURITYSETMANAGEMENTLib_LIBRARY_DEFINED__
#define __SECURITYSETMANAGEMENTLib_LIBRARY_DEFINED__

/* library SECURITYSETMANAGEMENTLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SECURITYSETMANAGEMENTLib;

EXTERN_C const CLSID CLSID_Issuer;

#ifdef __cplusplus

class DECLSPEC_UUID("B3091848-9674-4703-87CE-4DB145309BD4")
Issuer;
#endif
#endif /* __SECURITYSETMANAGEMENTLib_LIBRARY_DEFINED__ */

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
