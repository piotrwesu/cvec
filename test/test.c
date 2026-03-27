#include "cvec.h"
#include <stdio.h>

int loop_test()
{
    Cvec list;
    cvec_init(&list, sizeof(int));
    
    int number = 0;

    for(int i = 0; i < 10; i++){
        cvec_push_back(&list, &number);
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
        cvec_push_back(&tab, &i);


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

    for(double i = 0; i < 10; i++)
        cvec_push_back(&tab, &value);
   
    if(cvec_empty(&tab) == false){
        printf("Vector is not empty.\n");
        cvec_clear(&tab);
    }

    for(double i = 0; i < 10; i++)
        cvec_push_back(&tab, &value);

    for(double *i = cvec_begin(&tab); i != cvec_end(&tab); i++)
        printf("Number: %lf ", *i);

    cvec_pop_back(&tab);
    cvec_pop_back(&tab);

    cvec_shrink_to_fit(&tab);

    cvec_free(&tab);

    return 0;
}

int main()
{
    loop_test();
    reserve_test();
    clear();

    return 0;
}
