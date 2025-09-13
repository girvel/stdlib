#include "./test.h"
#include <stdbool.h>
#include <stdio.h>


bool _last_test_status;
char _last_test_message[STD_TEST_MESSAGE_CAPACITY];

void _std_test_fail() {
    _last_test_status = false;
}

char *_std_test_message() {
    return _last_test_message;
}

bool std_run_tests(Std_Test *tests) {
    bool ok = true;
    for (; tests->function != NULL; tests++) {
        _last_test_status = true;
        printf("%s", tests->name);
        tests->function();
        if (_last_test_status) {
            printf(" +\n");
        } else {
            ok = false;
            printf(" -\n%s\n", _last_test_message);
        }
    }
    return ok;
}
