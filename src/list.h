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
void *std_list_at(Std_List *self, size_t index);
void std_list_free(Std_List *self);

#define STD_LIST_PUSH_MANY(SELF, HEAD, ...) \
    do { \
        __typeof__ (HEAD) _std_list_push_many_values[] = {HEAD, __VA_ARGS__}; \
        std_list_push_many(SELF, sizeof(_std_list_push_many_values) / sizeof(__typeof__(HEAD)), _std_list_push_many_values); \
    } while (0)

#define STD_LIST_FOR(INDEX_IDENTIFIER, ELEMENT_IDENTIFIER, ITEM_TYPE, LIST) \
    Std_List *_std_list_for_list = LIST; \
    size_t _std_list_for_length = _std_list_for_list->length; \
    ITEM_TYPE *e = _std_list_for_length == 0 \
        ? NULL \
        : (ITEM_TYPE *)std_list_at(_std_list_for_list, 0); \
    for ( \
        size_t INDEX_IDENTIFIER = 0; \
        INDEX_IDENTIFIER < _std_list_for_length; \
        e = (ITEM_TYPE *)std_list_at(_std_list_for_list, ++INDEX_IDENTIFIER) \
    )

