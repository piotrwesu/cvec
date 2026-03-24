#include "cvec.h"
#include <stdio.h>

int main()
{
    cvec list;
    cvec_init(&list, sizeof(int));
    
    int number = 0;

    for(int i = 0; i < 10; i++){
        cvec_push(&list, &number);
        number++;
    }

    for(int i = 0; i < 10; i++)
        printf("Number: %d\n", cvec_at(int, &list, i));

    cvec_free(&list);

    return 0;
}
