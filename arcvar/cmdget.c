#include "arcvar.h"
#include "ntapi.h"

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

static int print_variable(_In_z_ const wchar_t *name)
{
    wchar_t buffer[BUFFER_SIZE];
    UNICODE_STRING us_name;
    RtlInitUnicodeString(&us_name, name);

    if (!NT_SUCCESS(NtQuerySystemEnvironmentValue(&us_name, buffer, BUFFER_SIZE, NULL)))
    {
        fprintf(stderr, "error: cannot query '%ls' system environment value\n", name);
        return 1;
    }

    printf("%ls : %ls\n", name, buffer);
    return 0;
}

int avc_get(int nargs, char *args[])
{

    wchar_t name[_MAX_PATH];
    mbstowcs(name, args[0], _MAX_PATH);
    return print_variable(name);
}
