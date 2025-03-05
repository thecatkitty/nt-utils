#include "arcvar.h"
#include "ntapi.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    BOOLEAN prev_privilege;

    av_command *cmd = avc_boot;
    int skip_args = 1;
    int status;

    if ((1 < argc) && (0 == stricmp("boot", argv[1])))
    {
        skip_args += 1;
    }
    else if ((1 < argc) && (0 == stricmp("get", argv[1])))
    {
        cmd = avc_get;
        skip_args += 1;
    }
    else if ((1 < argc) && (0 == stricmp("set", argv[1])))
    {
        cmd = avc_set;
        skip_args += 1;
    }

    if (!NT_SUCCESS(RtlAdjustPrivilege(
            SE_SYSTEM_ENVIRONMENT_PRIVILEGE,
            TRUE,
            FALSE,
            &prev_privilege)))
    {
        fprintf(stderr, "error: no permission to access system environment\n");
        return 1;
    }

    status = cmd(argc - skip_args, argv + skip_args);

    RtlAdjustPrivilege(
        SE_SYSTEM_ENVIRONMENT_PRIVILEGE,
        prev_privilege,
        FALSE,
        &prev_privilege);

    return status;
}
