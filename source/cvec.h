#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct Cvec {
    size_t size;
    size_t capacity;
    size_t stride;
    void *data;
}Cvec;

int cvec_init(Cvec *v, size_t stride);
void cvec_free(Cvec *v);

int cvec_reserve(Cvec *v, size_t new_capacity);
int cvec_shrink_to_fit(Cvec *v);
int cvec_resize(Cvec *v, size_t new_size);
void cvec_clear(Cvec *v);

int cvec_push_back(Cvec *v, const void* elem);
int cvec_insert(Cvec *v, size_t index, const void *elem);
void cvec_pop_back(Cvec *v);
int cvec_erase(Cvec *v, size_t index);

void *cvec_get_index(Cvec *v, size_t index);
#define cvec_at(type, vec, index) (*(type*)cvec_get_index(vec, index))
size_t cvec_get_size(const Cvec *v);
size_t cvec_get_capacity(const Cvec *v);
void *cvec_data(Cvec *v);
const void *cvec_cdata(const Cvec *v);

void *cvec_begin(Cvec *v);
const void *cvec_cbegin(const Cvec *v);
void *cvec_end(Cvec *v);
const void* cvec_cend(const Cvec *v);

void *cvec_last_index(Cvec *v);
#define cvec_back(type, vec) (*(type*)cvec_last_index(vec))
void *cvec_first_index(Cvec *v);
#define cvec_front(type, vec) (*(type*)cvec_first_index(vec))

bool cvec_empty(const Cvec *v);
