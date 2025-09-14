#include "../test.h"
#include <stdint.h>

#define T int32_t
#define N 4
#include "../vector.h"

#define STD_VECTOR_TESTS \
    {"test_std_vector_init", test_std_vector_init}, \
    {"test_std_vector_eq", test_std_vector_eq}

void test_std_vector_init() {
    Std_int32_tx4 v;
    std_int32_tx4_init(&v, 13, 37, 34, 35);
    STD_ASSERT(v.items[0] == 13);
    STD_ASSERT(v.items[1] == 37);
    STD_ASSERT(v.items[2] == 34);
    STD_ASSERT(v.items[3] == 35);
}

void test_std_vector_eq() {
    Std_int32_tx4 a;
    std_int32_tx4_init(&a, 13, 37, 34, 35);
    Std_int32_tx4 b;
    std_int32_tx4_init(&b, 13, 36, 34, 35);
    Std_int32_tx4 c;
    std_int32_tx4_init(&c, 13, 37, 34, 35);

    STD_ASSERT(!std_int32_tx4_eq(a, b));
    STD_ASSERT(std_int32_tx4_eq(a, c));
}
