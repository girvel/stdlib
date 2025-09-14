#include "list.h"


typedef struct {
    Std_List list;
} Std_String;

void std_string_from(Std_String *self, const char *base);
void std_string_format(Std_String *self, const char *format, ...);
char *std_string_c(Std_String self);
