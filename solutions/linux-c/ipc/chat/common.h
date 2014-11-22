#ifndef __COMMON_H__
#define __COMMON_H__

#ifdef __cplusplus
extern "C"{
#endif

    int pop(int fd, char *buffer);
    int push(int fd, const char *mssg);

#ifdef __cplusplus
}
#endif

#endif
