/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Dec 15 10:11:40 2006
 */
/* Compiler settings for F:\suddy\vc\KnowledgeBase\KnowledgeBase.idl:
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

const IID IID_IHelpTool = {0xE45421B6,0x9E1B,0x45B1,{0x99,0xB0,0x08,0x42,0x48,0x0B,0x26,0xC3}};


const IID LIBID_KNOWLEDGEBASELib = {0xCFE9FB7F,0x7CD8,0x4954,{0x99,0xAE,0x7F,0x8C,0xBD,0xA3,0x3F,0x9D}};


const CLSID CLSID_HelpTool = {0xDBCC8250,0x6FC1,0x4AEB,{0xA7,0x4A,0x64,0xA8,0xB3,0x6E,0x3E,0x2E}};


#ifdef __cplusplus
}
#endif

