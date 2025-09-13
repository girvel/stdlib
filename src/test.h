#pragma once

#include <stdio.h>
#include <stdbool.h>


typedef void (*Std_TestFunction)();

typedef struct {
    const char *name;
    Std_TestFunction function;
} Std_Test;

void _std_test_fail();
char *_std_test_message();
bool std_run_tests(Std_Test *tests);

#define STD_ASSERT(CONDITION) \
    if (!(CONDITION)) { \
        _std_test_fail(); \
        snprintf(_std_test_message(), STD_TEST_MESSAGE_CAPACITY, "%s:%i Assertion failed", __FILE__, __LINE__); \
        return; \
    }

#define STD_TEST_MESSAGE_CAPACITY 1024
