#include "vector.h"

Vector cross(Vector op1, Vector op2) {
    Vector result;

    result.x = op1.y * op2.z - op1.z * op2.y;
    result.y = op1.z * op2.x - op1.x * op2.z;
    result.z = op1.x * op2.y - op1.y * op2.x;

    return result;
}
