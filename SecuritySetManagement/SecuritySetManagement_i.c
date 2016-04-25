/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Jan 12 22:22:40 2007
 */
/* Compiler settings for F:\suddy\vc\SecuritySetManagement\SecuritySetManagement.idl:
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

const IID IID_IIssuer = {0x55C89FF3,0x1EF0,0x4675,{0x91,0x2C,0xB8,0x24,0x2A,0x00,0xDC,0x18}};


const IID LIBID_SECURITYSETMANAGEMENTLib = {0x65BFBC85,0xEE9E,0x4406,{0x87,0x44,0x79,0xFB,0x7B,0xCA,0xAB,0xCE}};


const CLSID CLSID_Issuer = {0xB3091848,0x9674,0x4703,{0x87,0xCE,0x4D,0xB1,0x45,0x30,0x9B,0xD4}};


#ifdef __cplusplus
}
#endif

