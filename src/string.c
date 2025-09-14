#include "./string.h"
#include <string.h>

void std_string_from(Std_String *self, const char *__restrict base) {
    std_list_init(&self->list, sizeof(char));
    std_list_push_many(&self->list, strlen(base), (void *)base);
}

void std_string_format(Std_String *self, const char *__restrict format, ...);

char *std_string_c(Std_String self) {
    return self.list.address;
}
