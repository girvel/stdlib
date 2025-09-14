#include "../test.h"
#include <stdint.h>

#define T int32_t
#define N 4
#include "../vector.h"
typedef Std_int32_tx4 int32x4;

#define STD_VECTOR_TESTS \
    {"test_std_vector", test_std_vector}

void test_std_vector() {
    int32x4 v;
    STD_ASSERT(true);
}
