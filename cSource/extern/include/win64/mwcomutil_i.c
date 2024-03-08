

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for win64\mwcomutil.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=IA64 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

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

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IMWUtil,0xC47EA90E,0x56D1,0x11d5,0xB1,0x59,0x00,0xD0,0xB7,0xBA,0x75,0x44);


MIDL_DEFINE_GUID(IID, LIBID_MWComUtil,0x395A3343,0x667E,0x49AF,0x86,0x5A,0xCD,0x4C,0xD0,0xA0,0xFA,0xE8);


MIDL_DEFINE_GUID(CLSID, CLSID_MWField,0xBEDBFAE8,0xFF6E,0x43E3,0xB5,0x85,0x6A,0x7C,0x32,0x9E,0x9C,0x1C);


MIDL_DEFINE_GUID(CLSID, CLSID_MWStruct,0x08CEDFCE,0x2949,0x4E3D,0xAE,0xDC,0x82,0x60,0xD6,0x0C,0xB0,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_MWComplex,0xBE880BF3,0x7F42,0x4FA8,0xB4,0x48,0x08,0xEE,0x71,0x37,0x0D,0x4A);


MIDL_DEFINE_GUID(CLSID, CLSID_MWSparse,0xAF87EE23,0xE01E,0x47CB,0xA7,0xB0,0xC0,0xE8,0xE2,0x26,0xC8,0xB1);


MIDL_DEFINE_GUID(CLSID, CLSID_MWArg,0x154A1743,0x3EA9,0x4E5D,0xBA,0x19,0xFE,0xEB,0x9B,0x6D,0xED,0x04);


MIDL_DEFINE_GUID(CLSID, CLSID_MWArrayFormatFlags,0xFB4D9359,0x9BB0,0x4D95,0xA0,0x5F,0xFF,0x2C,0xC0,0x03,0xB0,0x63);


MIDL_DEFINE_GUID(CLSID, CLSID_MWDataConversionFlags,0xBC8EA553,0x2369,0x45F6,0x96,0xB3,0x37,0xA3,0x6B,0xFB,0x45,0x14);


MIDL_DEFINE_GUID(CLSID, CLSID_MWUtil,0x44C75A68,0x56E8,0x49C1,0x89,0xA7,0x58,0xC3,0x58,0x2A,0x71,0xAB);


MIDL_DEFINE_GUID(CLSID, CLSID_MWFlags,0x72108EC4,0xB22E,0x4989,0xB4,0x75,0x02,0x8D,0x1E,0xD4,0x9E,0xE1);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



