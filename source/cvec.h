#pragma once

#include <stddef.h>

typedef struct Cvec {
    size_t size;
    size_t capacity;
    size_t stride;
    void *data;
}Cvec;

int cvec_init(Cvec *v, const size_t stride);
void cvec_free(Cvec *v);

int cvec_reserve(Cvec *v, const size_t new_capacity);

int cvec_push(Cvec *v, const void* elem);

void *cvec_get_index(Cvec *v, size_t index);
#define cvec_at(type, vec, index) (*(type*)cvec_get_index(vec, index))
void *cvec_begin(Cvec *v);
const void *cvec_cbegin(Cvec *v);
void *cvec_end(Cvec *v);
const void* cvec_cend(Cvec *v);
void *cvec_last_index(Cvec *v);
#define cvec_back(type, vec) (*(type*)cvec_last_index(vec))
