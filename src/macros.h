#pragma once

#include <assert.h>


#define _CONCAT4(A, B, C, D) A##B##C##D
#define CONCAT4(A, B, C, D) _CONCAT4(A, B, C, D)

#define STD_MAX2(A, B) ({ \
    __typeof__ (A) _a = (A); \
    __typeof__ (B) _b = (B); \
    _a > _b ? _a : _b; \
})

#define STD_MIN2(A, B) ({ \
    __typeof__ (A) _a = (A); \
    __typeof__ (B) _b = (B); \
    _a < _b ? _a : _b; \
}

#define STD_REF(VALUE) &(struct {__typeof__ (VALUE) _;}){(VALUE)}

#ifdef STD_SAFETY
    #define SAFETY_ASSERT(X) assert(X)
#else
    #define SAFETY_ASSERT(X) (void)(X)
#endif
