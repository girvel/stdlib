#include "./string.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void std_string_from(Std_String *self, const char *__restrict base) {
    std_list_init(&self->list, sizeof(char));
    std_list_push_many(&self->list, strlen(base), (void *)base);
}

void std_string_format(Std_String *self, const char *__restrict format, ...) {
    (void)self;

    va_list args;
    va_start(args, format);
    while (*format != '\0') {
        if (strncmp(format, "%i", 2) == 0) {
            printf("%i", va_arg(args, int));
            format += 2;
        } else if (strncmp(format, "%s", 2) == 0) {
            printf("%s", va_arg(args, const char *));
            format += 2;
        } else {
            printf("%c", *format);
            format++;
        }
    }
    va_end(args);
}

char *std_string_c(Std_String self) {
    return self.list.address;
}
