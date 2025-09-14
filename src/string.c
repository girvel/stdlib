#include "./string.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void std_string_from(Std_String *self, const char *__restrict base) {
    std_list_init(&self->list, sizeof(char));
    std_list_push_many(&self->list, strlen(base), (void *)base);
}

void std_string_format(Std_String *self, const char *__restrict format, ...) {
    Std_List *list = &self->list;
    std_list_init(list, sizeof(char));

    va_list args;
    va_start(args, format);
    size_t i = 0;
    while (*format != '\0') {
        printf("%.*s\n", (int) i, (char *)list->address);
        printf("%c\n", *format);
        if (strncmp(format, "%i", 2) == 0) {
            int value = va_arg(args, int);
            int length = snprintf(NULL, 0, "%i", value);
            std_list_extend(list, length);
            sprintf(std_list_at(*list, i), "%i", value);
            format += 2;
            i += length;
        } else if (strncmp(format, "%s", 2) == 0) {
            const char *value = va_arg(args, const char *);
            int length = strlen(value);
            std_list_extend(list, length);
            memcpy(std_list_at(*list, i), value, length);
            format += 2;
            i += length;
        } else {
            std_list_extend(list, 1);
            printf("1\n");
            *(char *)std_list_at(*list, i) = *format;
            format++;
            i++;
        }
    }

    std_list_extend(list, 1);
    *(char *)std_list_at(*list, i) = '\0';
    i++;

    self->list.length = i;
    va_end(args);
}

char *std_string_c(Std_String self) {
    return self.list.address;
}
