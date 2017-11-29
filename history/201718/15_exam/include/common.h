#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>

#ifndef NDEBUG
#define DBG(...) fprintf (stderr, __VA_ARGS__);
#else
#define DBG(...)
#endif


#endif
