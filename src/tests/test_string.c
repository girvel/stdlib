#include "../test.h"
#include "../string.h"
#include <string.h>

#define STD_STRING_TESTS \
    {"test_std_string_from", test_std_string_from}
    // {"test_std_string_format", test_std_string_format}

void test_std_string_from() {
    const char *source = "Hello, world!";
    Std_String demo;
    std_string_from(&demo, source);
    
    STD_ASSERT(source != demo.list.address);
    STD_ASSERT(strcmp(source, demo.list.address) == 0);
}

void test_std_string_format() {
    Std_String demo;
    std_string_format(&demo, "Hello, %s! The answer is %i!", "world", 42);

    STD_ASSERT(strcmp("Hello, world! The answer is 42!", std_string_c(demo)) == 0);
}
