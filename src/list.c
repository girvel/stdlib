#include "./list.h"
#include "./macros.h"
#include <stdlib.h>
#include <string.h>

void std_list_init(Std_List *self, size_t item_size) {
    self->address = NULL;
    self->item_size = item_size;
    self->length = 0;
    self->capacity = 0;
}

size_t _find_capacity_increase(size_t prev_capacity, size_t min_increase) {
    size_t increase; for (
        increase = prev_capacity;
        increase < min_increase;
        increase += MAX2(1U, increase)
    );
    return increase;
}

void std_list_extend_exact(Std_List *self, size_t capacity_increase) {
    size_t old_capacity = self->capacity;
    self->capacity += capacity_increase;
    void *new_address = realloc(self->address, self->capacity * self->item_size);
    if (self->address != new_address && self->address != NULL) {
        memcpy(self->address, new_address, old_capacity);
    }
    self->address = new_address;
}

void std_list_extend(Std_List *self, size_t min_capacity_increase) {
    std_list_extend_exact(
        self,
        _find_capacity_increase(self->capacity, min_capacity_increase)
    );
}

void std_list_push(Std_List *self, void *value) {
    if (self->length >= self->capacity) std_list_extend(self, 1);
    memcpy(self->address + self->item_size * self->length, value, self->item_size);
    // NEXT use std_list_at
    self->length++;
}

void *std_list_at(Std_List *self, size_t index) {
    return self->address + self->item_size * index;
}

void std_list_free(Std_List *self) {
    if (self->address == NULL) return;
    free(self->address);
    self->address = NULL;
    self->capacity = 0;
    self->length = 0;
}
