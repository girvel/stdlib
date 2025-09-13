#include <stdio.h>
#include "src/list.h"
#include "src/macros.h"

// goal: std_format("{0} is {0}", 42)
// or something like

int main() {
    // NEXT push_many
    // NEXT tests framework
    Std_List demo;
    std_list_init(&demo, sizeof(int));
    std_list_push(&demo, REF(1));
    std_list_push(&demo, REF(2));
    std_list_push(&demo, REF(3));
    std_list_push(&demo, REF(42));
    std_list_push(&demo, REF(69));
    std_list_push(&demo, REF(1337));

    // NEXT try foreach?
    for (size_t i = 0; i < demo.length; i++) {
        printf("demo[%zu] = %i\n", i, *(int *)std_list_at(&demo, i));
    }

    printf("demo.capacity = %zu\n", demo.capacity);

    printf("demo[%i] = %i\n", 9, *(int *)std_list_at(&demo, 9));

    return 0;
}
