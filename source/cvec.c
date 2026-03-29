#include "cvec.h"

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define CVEC_DEFAULT_CAPACITY 3
#define CVEC_RESIZE_FACTOR 3

int cvec_init(Cvec *v, const size_t stride)
{
    v->size = 0;
    v->stride = stride;
    v->capacity = CVEC_DEFAULT_CAPACITY;
    v->data = (void*)calloc(v->capacity, v->stride);
    if(v->data == NULL)
        return -1;

    return 0;
};

void cvec_free(Cvec *v)
{
    if(v->data != NULL){
        v->size = 0;
        v->capacity = 0;
        free(v->data);
        v->data = NULL;
    }
};

int cvec_reserve(Cvec *v, const size_t new_capacity)
{
    if(new_capacity <= v->capacity)
        return 0;

    void *ptr= realloc(v->data, new_capacity * v->stride);
    if(ptr == NULL)
        return -1;

    v->data = ptr;
    v->capacity = new_capacity;

    return 0;
};

int cvec_shrink_to_fit(Cvec *v)
{
    if(v->capacity <= v->size * CVEC_RESIZE_FACTOR)
        return 0;

    if(v->capacity == 0){
        cvec_clear(v);

        return 0;
    }

    void *ptr = realloc(v->data, v->size * v->stride);
    if(ptr == NULL)
        return -1;
    else{
        v->data = ptr;
        v->capacity = v->size;
    }

    return 0;
}

int cvec_resize(Cvec *v, const size_t new_size)
{
    if(new_size <= v->size)
        v->size = new_size;
    else {
        void *ptr = realloc(v->data, new_size * v->stride * CVEC_RESIZE_FACTOR);    
        if(ptr == NULL){
            return -1;
        }
        else{
            v->data = ptr;
            v->capacity = new_size * CVEC_RESIZE_FACTOR;
            v->size = new_size;
        }
    }

    return 0;
};

void cvec_clear(Cvec *v)
{
   v->size = 0; 
};

int cvec_push_back(Cvec *v, const void* elem)
{
    if(v->size == v->capacity) {
        void *ptr = realloc(v->data, v->capacity * v->stride * CVEC_RESIZE_FACTOR);    
        if(ptr == NULL){
            return -1;
        }
        else{
            v->data = ptr;
            v->capacity *= CVEC_RESIZE_FACTOR;
        }
    }

    void *dest = (uint8_t*)v->data + v->size * v->stride;
    memcpy(dest, elem, v->stride);
    v->size++;

    return 0;
};

int cvec_insert(Cvec *v, const size_t index, const void *elem)
{
    if(index > v->size)
        return -1;

    if(v->size == v->capacity)
        if(cvec_reserve(v, v->capacity * CVEC_RESIZE_FACTOR))
            return -1;
    
    size_t moving_size = (v->size - index) * v->stride;
    void *dest = (uint8_t*)v->data + index * v->stride; 

    if(moving_size > 0){
        memmove(dest + v->stride, dest, moving_size); 
    }

    memcpy(dest, elem, v->stride);

    v->size++;

    return 0;
}

void cvec_pop_back(Cvec *v)
{
    if(v->size > 0)
        v->size--;
};

void *cvec_get_index(Cvec *v, const size_t index)
{
    if(index >= v->size)
        return NULL;

    return (uint8_t*)v->data + index * v->stride;
};

void *cvec_begin(Cvec *v)
{
    return (uint8_t*)v->data;
};

const void *cvec_cbegin(Cvec *v)
{
    return (const uint8_t*)v->data;
};

void *cvec_end(Cvec *v)
{
    return (uint8_t*)v->data + v->size * v->stride;
}

const void* cvec_cend(Cvec *v)
{
    return (const void*)v->data + v->size * v->stride;
};

void *cvec_last_index(Cvec *v)
{
    if(v->size == 0)
        return NULL;

    return (uint8_t*)v->data + (v->size - 1) * v->stride;

};

void *cvec_first_index(Cvec *v)
{
    if(v->size == 0)
        return NULL;

    return (uint8_t*)v->data;
};

bool cvec_empty(Cvec *v)
{
    return v->size == 0; 
};
