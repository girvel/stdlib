#include "list.h"


typedef struct {
    Std_List list;
} Std_String;

void std_string_from(Std_String *self, const char *__restrict base);
void std_string_format(Std_String *self, const char *__restrict format, ...);
char *std_string_c(Std_String self);
