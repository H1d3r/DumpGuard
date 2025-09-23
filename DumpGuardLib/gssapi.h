// Copyright (C) 2024 Evan McBroom
//
// RFC2743: Generic Security Service Application Program Interface Version 2, Update 1
//
#ifndef __GSS_API_H__
#define __GSS_API_H__

#include "msasn1.h"

#define InitialContextToken_PDU  0

#define SIZE_GSSAPI_Module_PDU_0 sizeof(InitialContextToken)

#ifdef __cplusplus
extern "C" {
#endif

    struct InitialContextToken;

    typedef ASN1objectidentifier_t MechType;
    typedef ASN1open_t SubsequentContextToken;
    typedef ASN1open_t PerMsgToken;
    typedef ASN1open_t SealedMessage;

    typedef struct InitialContextToken {
        MechType thisMech;
        ASN1uint16_t tokId;
        ASN1open_t innerToken;
    } InitialContextToken;

    extern ASN1module_t GSSAPI_Module;
    extern BOOL ASN1CALL GSSAPI_Module_Startup();
    extern void ASN1CALL GSSAPI_Module_Cleanup();

    BOOL GssApiEncodeData(PVOID pDataStruct, DWORD dwPdu, PVOID* ppvData, ULONG* pcbData);
    BOOL GssApiDecodeData(PVOID pvData, ULONG cbData, DWORD dwPdu, PVOID* ppDataStruct);
    BOOL GssApiFreeDecoded(PVOID pDataStruct, DWORD dwPdu);

#ifdef __cplusplus
} // Closes extern "C" above
namespace Asn1 {
    namespace Gssapi {
        using InitialContextToken = ::InitialContextToken;
    }
}
#endif

#endif