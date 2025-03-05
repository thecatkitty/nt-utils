#include "arcvar.h"

#include <wchar.h>

enum
{
    BTV_SYSTEMPARTITION,
    BTV_OSLOADER,
    BTV_OSLOADPARTITION,
    BTV_OSLOADFILENAME,
    BTV_LOADIDENTIFIER,
    BTV_OSLOADOPTIONS,
    BTV_COUNTDOWN,
    BTV_MAX
};

static char *BOOT_VARIABLES[BTV_MAX] = {"SYSTEMPARTITION",
                                        "OSLOADER",
                                        "OSLOADPARTITION",
                                        "OSLOADFILENAME",
                                        "LOADIDENTIFIER",
                                        "OSLOADOPTIONS",
                                        "COUNTDOWN"};

int avc_boot(int nargs, char *args[])
{
    int i;

    for (i = 0; i < BTV_MAX; i++)
    {
        int status = avc_get(1, BOOT_VARIABLES + i);
        if (0 != status)
        {
            return status;
        }
    }

    return 0;
}
