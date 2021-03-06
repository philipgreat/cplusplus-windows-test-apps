/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Dec 15 10:11:40 2006
 */
/* Compiler settings for F:\suddy\vc\KnowledgeBase\KnowledgeBase.idl:
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

#ifndef __KnowledgeBase_h__
#define __KnowledgeBase_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IHelpTool_FWD_DEFINED__
#define __IHelpTool_FWD_DEFINED__
typedef interface IHelpTool IHelpTool;
#endif 	/* __IHelpTool_FWD_DEFINED__ */


#ifndef __HelpTool_FWD_DEFINED__
#define __HelpTool_FWD_DEFINED__

#ifdef __cplusplus
typedef class HelpTool HelpTool;
#else
typedef struct HelpTool HelpTool;
#endif /* __cplusplus */

#endif 	/* __HelpTool_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IHelpTool_INTERFACE_DEFINED__
#define __IHelpTool_INTERFACE_DEFINED__

/* interface IHelpTool */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IHelpTool;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E45421B6-9E1B-45B1-99B0-0842480B26C3")
    IHelpTool : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddToHelpStore( 
            /* [in] */ BSTR title,
            /* [in] */ BSTR content,
            /* [in] */ BSTR keywords) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHelpToolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IHelpTool __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IHelpTool __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IHelpTool __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IHelpTool __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IHelpTool __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IHelpTool __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IHelpTool __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddToHelpStore )( 
            IHelpTool __RPC_FAR * This,
            /* [in] */ BSTR title,
            /* [in] */ BSTR content,
            /* [in] */ BSTR keywords);
        
        END_INTERFACE
    } IHelpToolVtbl;

    interface IHelpTool
    {
        CONST_VTBL struct IHelpToolVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHelpTool_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHelpTool_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHelpTool_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHelpTool_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IHelpTool_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IHelpTool_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IHelpTool_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IHelpTool_AddToHelpStore(This,title,content,keywords)	\
    (This)->lpVtbl -> AddToHelpStore(This,title,content,keywords)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHelpTool_AddToHelpStore_Proxy( 
    IHelpTool __RPC_FAR * This,
    /* [in] */ BSTR title,
    /* [in] */ BSTR content,
    /* [in] */ BSTR keywords);


void __RPC_STUB IHelpTool_AddToHelpStore_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHelpTool_INTERFACE_DEFINED__ */



#ifndef __KNOWLEDGEBASELib_LIBRARY_DEFINED__
#define __KNOWLEDGEBASELib_LIBRARY_DEFINED__

/* library KNOWLEDGEBASELib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_KNOWLEDGEBASELib;

EXTERN_C const CLSID CLSID_HelpTool;

#ifdef __cplusplus

class DECLSPEC_UUID("DBCC8250-6FC1-4AEB-A74A-64A8B36E3E2E")
HelpTool;
#endif
#endif /* __KNOWLEDGEBASELib_LIBRARY_DEFINED__ */

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
