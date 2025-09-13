#include <stdio.h>
#include "src/list.h"

// goal: std_format("{0} is {0}", 42)
// or something like

int main() {
    // NEXT tests framework
    Std_List demo;
    std_list_init(&demo, sizeof(int));
    STD_LIST_PUSH_MANY(&demo, 1, 2, 3, 42, 69, 1337);

    // NEXT safe empty loop
    STD_LIST_FOR(i, e, int, &demo) {
        printf("demo[%zu] = %i\n", i, *e);
    }

    printf("demo.capacity = %zu\n", demo.capacity);

    return 0;
}
