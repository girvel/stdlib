#include "macros.h"


#ifndef T
    #define T int
#endif

#ifndef N
    #define N 4
#endif

typedef struct {
    T items[N];
} CONCAT4(Std_, T, x, N);

#undef T
#undef N
