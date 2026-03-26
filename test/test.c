#include "cvec.h"
#include <stdio.h>

int loop_test()
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

int reserve_test()
{
    Cvec tab;
    cvec_init(&tab, sizeof(int));
    int n = 10;

    cvec_reserve(&tab, n);

    for(int i = 0; i < n; i++)
        cvec_push(&tab, &i);


    for(const int *it = cvec_cbegin(&tab); it != cvec_cend(&tab); it++)
        printf("Number: %d\n", *it);

    printf("First value: %d\n", cvec_front(int, &tab));
    printf("Last value: %d\n",cvec_back(int, &tab));

    cvec_clear(&tab);

    cvec_free(&tab);

    return 0;
}

int clear()
{
    Cvec tab;
    cvec_init(&tab, sizeof(double));

    double value = 5;

    for(int *it = cvec_begin(&tab); it != cvec_end(&tab); it++)
        cvec_push(&tab, &value);
    
    cvec_clear(&tab);

    for(int *it = cvec_begin(&tab); it != cvec_end(&tab); it++)
        cvec_push(&tab, &value);

    return 0;
}

int main()
{
    loop_test();
    reserve_test();
    clear();

    return 0;
}
