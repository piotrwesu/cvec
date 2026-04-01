#include "cvec.h"
#include <stdio.h>
#include <time.h>

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

    cvec_insert(&tab, 5, &n);
    cvec_erase(&tab, 5);
    
    cvec_clear(&tab);

    cvec_insert(&tab, 0, &n);
    cvec_erase(&tab, 0);

    cvec_free(&tab);

    return 0;
}

int clear_test()
{
    Cvec tab;
    cvec_init(&tab, sizeof(double));

    double value = 5;

    for(int i = 0; i < 10; i++)
        cvec_push_back(&tab, &value);
   
    if(cvec_empty(&tab) == false){
        printf("Vector is not empty.\n");
        cvec_clear(&tab);
    }

    for(int i = 0; i < 10; i++)
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
#if defined(__unix__) || defined(__APPLE__)
    const long long N = 20000000LL;
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
#endif

    loop_test();
    reserve_test();
    clear_test();

#if defined(__unix__)|| defined(__APPLE__)
    clock_gettime(CLOCK_MONOTONIC, &end);
    double ns_time = ((end.tv_sec - start.tv_sec) * 1e9 +
                         (end.tv_nsec - start.tv_nsec)) / (double)N;

    printf("%.4f ns/op\n", ns_time);
#endif

    return 0;
}
