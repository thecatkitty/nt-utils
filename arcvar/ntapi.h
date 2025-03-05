#ifndef _NTAPI_H_
#define _NTAPI_H_

#include <windows.h>
#include <ntdef.h>

#ifndef _In_
#define _In_
#define _In_z_
#define _In_opt_
#define _Out_
#define _Out_opt_
#endif

#define SE_SYSTEM_ENVIRONMENT_PRIVILEGE (22L)

NTSTATUS
NTAPI
NtQuerySystemEnvironmentValue(
    _In_ PUNICODE_STRING VariableName,
    _Out_ PWCHAR Value,
    _In_ ULONG ValueBufferLength,
    _Out_opt_ PULONG RequiredLength);

NTSTATUS
NTAPI
NtSetSystemEnvironmentValue(
    _In_ PUNICODE_STRING VariableName,
    _In_ PUNICODE_STRING Value);

NTSTATUS
NTAPI
RtlAdjustPrivilege(
    _In_ ULONG Privilege,
    _In_ BOOLEAN Enable,
    _In_ BOOLEAN Client,
    _Out_ PBOOLEAN WasEnabled);

VOID RtlInitUnicodeString(
    _Out_ PUNICODE_STRING DestinationString,
    _In_opt_ PCWSTR SourceString);

#endif // _NTAPI_H_
