#include "./string.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void std_string_from(Std_String *self, const char *__restrict base) {
    std_list_init(&self->list, sizeof(char));
    std_list_push_many(&self->list, strlen(base), (void *)base);
}

// size_t _get_format_size(const char *__restrict format, ...) {
//     size_t result = sprintf
// }

void std_string_format(Std_String *self, const char *__restrict format, ...) {
    std_list_init(&self->list, sizeof(char));
    std_list_extend_exact(&self->list, strlen(format) + 10);

    va_list args;
    va_start(args, format);
    char *next = self->list.address;
    while (*format != '\0') {
        if (strncmp(format, "%i", 2) == 0) {
            format += 2;
            next += sprintf(next, "%i", va_arg(args, int));
        } else if (strncmp(format, "%s", 2) == 0) {
            const char *value = va_arg(args, const char *);
            int length = strlen(value);
            memcpy(next, value, length);
            format += 2;
            next += length;
        } else {
            *next = *format;
            format++;
            next++;
        }
    }

    *next = '\0';
    next++;

    self->list.length = (next - (char *)self->list.address);
    va_end(args);
}

char *std_string_c(Std_String self) {
    return self.list.address;
}
