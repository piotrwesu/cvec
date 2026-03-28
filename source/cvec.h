#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct Cvec {
    size_t size;
    size_t capacity;
    size_t stride;
    void *data;
}Cvec;

int cvec_init(Cvec *v, const size_t stride);
void cvec_free(Cvec *v);

int cvec_reserve(Cvec *v, const size_t new_capacity);
int cvec_shrink_to_fit(Cvec *v);
int cvec_resize(Cvec *v, const size_t new_size);
void cvec_clear(Cvec *v);

int cvec_push_back(Cvec *v, const void* elem);
void cvec_pop_back(Cvec *v);

void *cvec_get_index(Cvec *v, const size_t index);
#define cvec_at(type, vec, index) (*(type*)cvec_get_index(vec, index))

void *cvec_begin(Cvec *v);
const void *cvec_cbegin(Cvec *v);
void *cvec_end(Cvec *v);
const void* cvec_cend(Cvec *v);

void *cvec_last_index(Cvec *v);
#define cvec_back(type, vec) (*(type*)cvec_last_index(vec))
void *cvec_first_index(Cvec *v);
#define cvec_front(type, vec) (*(type*)cvec_first_index(vec))

bool cvec_empty(Cvec *v);
