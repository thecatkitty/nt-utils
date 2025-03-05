#include "arcvar.h"
#include "ntapi.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE_LENGTH 4096

static int set_variable(_In_z_ const wchar_t *name, _In_z_ const wchar_t *value)
{
    UNICODE_STRING us_name, us_value;
    RtlInitUnicodeString(&us_name, name);
    RtlInitUnicodeString(&us_value, value);

    if (!NT_SUCCESS(NtSetSystemEnvironmentValue(&us_name, &us_value)))
    {
        fprintf(stderr, "error: cannot set '%ls' system environment value\n", name);
        return 1;
    }

    printf("done.\n");
    return 0;
}

int avc_set(int nargs, char *args[])
{
    wchar_t name[_MAX_PATH], value[MAX_VALUE_LENGTH];
    mbstowcs(name, args[0], _MAX_PATH);
    mbstowcs(value, args[1], MAX_VALUE_LENGTH);

    printf("setting '%ls' to: %ls\n", name, value);
    return set_variable(name, value);
}
