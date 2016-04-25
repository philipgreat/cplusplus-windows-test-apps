/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Jan 11 16:30:56 2007
 */
/* Compiler settings for F:\suddy\vc\TestCom2\TestCom2.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IKey = {0x00CCD93A,0xA357,0x499D,{0x99,0xF4,0x5B,0xF9,0x5B,0x9E,0x05,0xF4}};


const IID LIBID_TESTCOM2Lib = {0x4BEC945F,0x8932,0x4A3E,{0xBE,0x4B,0xF8,0xC2,0x79,0xF5,0x8E,0xC6}};


const CLSID CLSID_Key = {0xD927614A,0xB947,0x416E,{0x9E,0x86,0x33,0xF3,0x89,0xA8,0x78,0xB0}};


#ifdef __cplusplus
}
#endif

