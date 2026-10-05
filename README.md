# Cvec - Dynamic array for C. Equivalent to std::vector from c++.

`cvec` is a lightweight, generic dynamic array (vector) implementation for C, inspired by C++ `std::vector`. It stores elements of any type using a contiguous memory buffer and supports push, insert, erase, reserve, resize.

The library is designed to be:

* simple (small API)
* portable C (C99)


## Features

* Generic container (`void*` + element size)
* Contiguous memory


## Quick Example

```c
#include "cvec.h"

int main()
{
    Cvec v;
    cvec_init(&v, sizeof(int));

    for (int i = 0; i < 10; ++i)
        cvec_push_back(&v, &i);

    int number = cvec_at(int, &v, 1);

    for(int *it = cvec_begin(&v); it != cvec_end(&v); it++)
        printf("%d\n", *it);

    cvec_free(&v);
}
```

## API

### Initialization

```c
int  cvec_init(Cvec *v, size_t elem_size);
void cvec_free(Cvec *v);
```

### Capacity

```c
int    cvec_reserve(Cvec *v, size_t new_capacity);
int    cvec_shrink_to_fit(Cvec *v);
int    cvec_resize(Cvec *v, size_t new_size);
void   cvec_clear(Cvec *v);
size_t cvec_size(const Cvec *v);
size_t cvec_capacity(const Cvec *v);

```
### Modifiers

```c
int   cvec_push_back(Cvec *v, const void *elem);
int   cvec_insert(Cvec *v, size_t index, const void *elem);
void  cvec_pop_back(Cvec *v);
int   cvec_erase(Cvec *v, size_t index);
```

### Element access

```c
void *cvec_get_index(Cvec *v, size_t index);
(*(type*))  cvec_at(type, Cvec *v, size_t index);
(type*)      cvec_at_ptr(type, vec, index)

size_t      cvec_size(const Cvec *v);
size_t      cvec_capacity(const Cvec *v);
void        *cvec_data(Cvec *v);
const void  *cvec_cdata(const Cvec *v);

void        *cvec_begin(Cvec*v);
const void  *cvec_cbegin(const Cvec *v);
void        *cvec_end(Cvec *v);
const void  *cvec_cend(const Cvec *v);

(*(type*))  cvec_back(type, Cvec *v);
(*(type*))  cvec_back(type, Cvec *v);
(*(type*))  cvec_front(type, Cvec *v);
bool        cvec_empty(const Cvec *v);
```

## Design Notes

The implementation separates memory management from element operations:

| Function    | Responsibility    |
| ----------- | ----------------- |
| reserve     | allocate memory   |
| grow        | increase capacity |
| push_slot   | increase size     |
| insert_slot | shift elements    |
| push_back   | copy element      |
| insert      | copy element      |

This keeps the implementation simple and fast.


## Building

Example CMake:

```cmake
add_library(cvec cvec.c)
target_include_directories(cvec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```


## Speed

Very close to std::vector


## License

GPL-3.0 license
