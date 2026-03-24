#include "cvec.h"

#include <stdlib.h>
#include <stdio.h> 
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
    if(v->data == NULL){
        fprintf(stderr, "Can't allocate memory for Cvec vector.\n");
        return -1;
    }

    return 0;
};

void cvec_free(Cvec *v)
{
    free(v->data);
    v->data = NULL;
};

int cvec_push(Cvec *v, const void* elem)
{
    if(v->size == v->capacity) {
        void *ptr = realloc(v->data, v->capacity * v->stride * CVEC_RESIZE_FACTOR);    
        if(ptr == NULL){
            fprintf(stderr, "Can't realloc memory for pushing new element to Cvec vector.\n");
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

void *cvec_get_index(Cvec *v, size_t index)
{
    if(index >= v->size){
        perror("Buffer overflow in index Cvec vector.\n");
        return NULL;
    }

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
