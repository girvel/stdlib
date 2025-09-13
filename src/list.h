#pragma once

#include <stddef.h>


typedef struct {
    void *address;
    size_t item_size, capacity, length;
} Std_List;

void std_list_init(Std_List *self, size_t item_size);
void std_list_extend_exact(Std_List *self, size_t capacity_increase);
void std_list_extend(Std_List *self, size_t min_capacity_increase);
void std_list_push(Std_List *self, void *value);
void std_list_push_many(Std_List *self, size_t count, void *values);
// NEXT macro
void *std_list_at(Std_List *self, size_t index);
void std_list_free(Std_List *self);
