#include "cvec.h"
#include <stdio.h>

int main()
{
    cvec list;
    cvec_init(&list, sizeof(int));
    
    int number = 1;

    cvec_push(&list, &number);

    printf("Number: %d\n", *(int*)list.data); 
    printf("Number: %d", cvec_at(int, &list, 0));

    cvec_free(&list);

    return 0;
}
