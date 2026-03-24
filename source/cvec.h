#pragma once

#include <stddef.h>

typedef struct cvec {
    size_t size;
    size_t capacity;
    size_t stride;
    void *data;
}cvec;

int cvec_init(cvec *v, const size_t stride);
void cvec_free(cvec *v);

int cvec_push(cvec *v, const void* elem);

void *cvec_get_index(cvec *v, size_t index);
#define cvec_at(type, vec, index) (*(type*)cvec_get_index(vec, index))
void *cvec_begin(cvec *v);
void *cvec_end(cvec *v);
