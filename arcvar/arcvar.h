#ifndef _ARCVAR_H_
#define _ARCVAR_H_

typedef int av_command(int nargs, char *args[]);

extern av_command avc_boot;
extern av_command avc_get;
extern av_command avc_set;

#endif // _ARCVAR_H_
