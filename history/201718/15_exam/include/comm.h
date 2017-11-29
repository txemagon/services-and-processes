#ifndef __COMM_H__
#define __COMM_H__

#include <sys/types.h>
#include <signal.h>

#ifdef __cplusplus
extern "C"
{
#endif

    extern void enviar(pid_t parent, unsigned char data);


#ifdef __cplusplus
}
#endif

#endif
