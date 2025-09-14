#include "src/test.h"
#include "src/tests/test_list.c"
#include "src/tests/test_string.c"
#include "src/tests/test_vector.c"

// GOAL std_string_format(&str, "Hello, %s! The answer is %i", "world", 42)
//   or something like

// GOAL Std_Vector + `./nob build src/vector.c`

int main() {
    return !std_run_tests((Std_Test []) {
        STD_LIST_TESTS,
        STD_STRING_TESTS,
        STD_VECTOR_TESTS,
        {NULL, NULL},
    });
}
