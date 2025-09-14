#include "../test.h"
#include "../string.h"
#include <string.h>

#define STD_STRING_TESTS \
    {"test_std_string_from", test_std_string_from}

void test_std_string_from() {
    const char *source = "Hello, world!";
    Std_String demo;
    std_string_from(&demo, source);
    
    STD_ASSERT(source != demo.list.address);
    STD_ASSERT(strcmp(source, demo.list.address) == 0);
}
