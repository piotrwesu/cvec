#include "cvec.h"
#include <stdio.h>

int main()
{
    Cvec list;
    cvec_init(&list, sizeof(int));
    
    int number = 0;

    for(int i = 0; i < 10; i++){
        cvec_push(&list, &number);
        number++;
    }

    for(int i = 0; i < 10; i++)
        printf("Number: %d\n", cvec_at(int, &list, i));
    

    for(int *it = cvec_begin(&list); it != cvec_end(&list); it++)
        printf("Number: %d\n", *it);

    cvec_free(&list);

    return 0;
}
