#include "cvec.h"

#include <stdlib.h>
#include <stdio.h> 
#include <string.h>

#define CVEC_DEFAULT_CAPACITY 3
#define CVEC_RESIZE_FACTOR 3

int cvec_init(cvec *v, const size_t stride)
{
    v->size = 0;
    v->stride = stride;
    v->capacity = CVEC_DEFAULT_CAPACITY;
    v->data = (void*)calloc(v->capacity, v->stride);
    if(v->data == NULL){
        fprintf(stderr, "Can't allocate memory for cvec vector.\n");
        return -1;
    }

    return 0;
};

void cvec_free(cvec *v)
{
    free(v->data);
    v->data = NULL;
};

int cvec_push(cvec *v, const void* elem)
{
    if(v->size == v->capacity) {
        void *ptr = realloc(v->data, v->capacity * v->stride * CVEC_RESIZE_FACTOR);    
        if(ptr == NULL){
            fprintf(stderr, "Can't realloc memory for pushing new element to cvec vector.\n");
            return -1;
        }
        else{
            v->data = ptr;
            v->capacity = v->capacity * CVEC_RESIZE_FACTOR;
        }
    }

    void *dest = (char*)v->data + v->size * v->stride;
    memcpy(dest, elem, v->stride);
    v->size++;

    return 0;
};

void *cvec_get_index(cvec *v, size_t index)
{
    if(index >= v->size){
        perror("Buffer overflow in index cvec vector.\n");
        return NULL;
    }

    return (char*)v->data + index * v->stride;
};

void *cvec_begin(cvec *v)
{
    return (char*)v->data;
};

void *cvec_end(cvec *v)
{
    return (char*)v->data + v->size * v->stride;
}
