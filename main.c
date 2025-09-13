#include <stdio.h>
#include "src/list.h"
#include "src/test.h"
#include "src/tests/test_list.c"

// goal: std_format("{0} is {0}", 42)
// or something like

// NEXT rename to test.c
// NEXT really test the list
int main() {
    // Std_List demo;
    // std_list_init(&demo, sizeof(int));
    // STD_LIST_PUSH_MANY(&demo, 1, 2, 3, 42, 69, 1337);

    // STD_LIST_FOR(i, e, int, &demo) {
    //     printf("demo[%zu] = %i\n", i, *e);
    // }

    // printf("demo.capacity = %zu\n", demo.capacity);

    std_run_tests((Std_Test []) {
        {"test_success", test_success},
        {"test_failure", test_failure},
        {NULL, NULL},
    });

    return 0;
}
