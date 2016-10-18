#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct TVector {
    int x;
    int y;
    int z;
} Vector;

#ifdef __cplusplus
extern "C" {
#endif

    extern Vector cross(Vector op1, Vector op2);

#ifdef __cplusplus
}
#endif

#endif
