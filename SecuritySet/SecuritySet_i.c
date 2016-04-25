/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Jan 14 19:04:52 2007
 */
/* Compiler settings for F:\suddy\vc\SecuritySet\SecuritySet.idl:
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

const IID IID_IHaspKey = {0xA31FF10C,0xB204,0x4231,{0x88,0x5B,0x62,0x1F,0x0C,0xC1,0x99,0x24}};


const IID LIBID_SECURITYSETLib = {0xFB3772A1,0xF645,0x4AE2,{0xAE,0x96,0x97,0x70,0x98,0x94,0xFA,0x0C}};


const CLSID CLSID_HaspKey = {0xCCD223DE,0xB3FB,0x4F5A,{0xBB,0x71,0x52,0x68,0xE2,0xFC,0xB4,0xAB}};


#ifdef __cplusplus
}
#endif

