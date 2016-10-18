#include "vector.h"
#include "interfaz.h"

int main() {
    Vector v1 = {1,  2, 3},
           v2 = {2, -1, 3};

    print( cross(v1, v2) );

    return 0;
}
