#pragma once

#include <assert.h>


#define MAX2(A, B) ({ \
    __typeof__ (A) _a = (A); \
    __typeof__ (B) _b = (B); \
    _a > _b ? _a : _b; \
})

#define MIN2(A, B) ({ \
    __typeof__ (A) _a = (A); \
    __typeof__ (B) _b = (B); \
    _a < _b ? _a : _b; \
}

#define REF(VALUE) &(struct {__typeof__ (VALUE) _;}){(VALUE)}

#ifdef STD_SAFETY
    #define SAFETY_ASSERT(X) assert(X)
#else
    #define SAFETY_ASSERT(X) (void)(X)
#endif
