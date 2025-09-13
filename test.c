#include "src/test.h"
#include "src/tests/test_list.c"

// goal: std_format("{0} is {0}", 42)
// or something like

int main() {
    std_run_tests((Std_Test []) {
        {"test_std_list_push", test_std_list_push},
        {"test_std_list_push_many", test_std_list_push_many},
        {"test_std_list_usage", test_std_list_usage},
        {NULL, NULL},
    });

    return 0;
}
