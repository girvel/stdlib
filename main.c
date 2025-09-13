#include <stdio.h>
#include "src/list.h"

// goal: std_format("{0} is {0}", 42)
// or something like

int main() {
    // NEXT push_many
    // NEXT tests framework
    Std_List demo;
    std_list_init(&demo, sizeof(int));

    int values[] = {1, 2, 3, 42, 69, 1337};
    std_list_push_many(&demo, sizeof(values) / sizeof(int), values);

    // NEXT try foreach?
    for (size_t i = 0; i < demo.length; i++) {
        printf("demo[%zu] = %i\n", i, *(int *)std_list_at(&demo, i));
    }

    printf("demo.capacity = %zu\n", demo.capacity);

    return 0;
}
