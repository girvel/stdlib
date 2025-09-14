#include "macros.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>


#ifndef T
    #define T int
#endif

#ifndef N
    #define N 4
#endif

#define _STD_VECTOR_SHORT CONCAT3(T, x, N)
#define _STD_VECTOR_FULL CONCAT2(Std_, _STD_VECTOR_SHORT)

typedef struct {
    T items[N];
} _STD_VECTOR_FULL;

void CONCAT3(std_, _STD_VECTOR_SHORT, _init)(_STD_VECTOR_FULL *self, ...) {
    va_list args;
    va_start(args, self);
    for (size_t i = 0; i < N; ++i) {
        self->items[i] = va_arg(args, T);
    }
    va_end(args);
}

bool CONCAT3(std_, _STD_VECTOR_SHORT, _eq)(_STD_VECTOR_FULL self, _STD_VECTOR_FULL other) {
    for (size_t i = 0; i < N; ++i) {
        if (self.items[i] != other.items[i]) return false;
    }
    return true;
}

#undef T
#undef N
