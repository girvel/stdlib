#include "../list.h"
#include "../test.h"
#include "../macros.h"
#include <stdint.h>

#define STD_LIST_TESTS \
    {"test_std_list_push", test_std_list_push}, \
    {"test_std_list_push_many", test_std_list_push_many}, \
    {"test_std_list_usage", test_std_list_usage}

void test_std_list_push() {
    Std_List demo;
    std_list_init(&demo, sizeof(int32_t));
    std_list_push(&demo, STD_REF(1));
    std_list_push(&demo, STD_REF(2));
    std_list_push(&demo, STD_REF(3));

    int32_t *inner = (int32_t *)demo.address;
    STD_ASSERT(inner[0] == 1);
    STD_ASSERT(inner[1] == 2);
    STD_ASSERT(inner[2] == 3);

    STD_ASSERT(demo.length == 3);
    STD_ASSERT(demo.capacity == 4);

    std_list_free(&demo);
}

void test_std_list_push_many() {
    Std_List demo;
    std_list_init(&demo, sizeof(int32_t));
    int32_t content[] = {1, 2, 3};
    std_list_push_many(&demo, 3, content);

    int32_t *inner = (int32_t *)demo.address;
    STD_ASSERT(inner[0] == 1);
    STD_ASSERT(inner[1] == 2);
    STD_ASSERT(inner[2] == 3);

    STD_ASSERT(demo.length == 3);
    STD_ASSERT(demo.capacity == 4);

    std_list_free(&demo);
}

void test_std_list_usage() {
    Std_List demo;
    std_list_init(&demo, sizeof(int32_t));
    STD_LIST_PUSH_MANY(&demo, 1, 2, 3, 42, 69, 1337);

    int32_t expected_values[] = {1, 2, 3, 42, 69, 1337};
    STD_LIST_FOR(i, e, int32_t, &demo) {
        STD_ASSERT(expected_values[i] == *e);
    }

    STD_ASSERT(demo.capacity == 8);
    STD_ASSERT(demo.length == 6);
    std_list_free(&demo);
}
