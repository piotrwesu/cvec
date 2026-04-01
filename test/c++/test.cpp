#include <vector>
#include <stdio.h>
#include <time.h>

int loop_test()
{
    std::vector<int> list;
    int number = 0;

    for(int i = 0; i < 10; i++){
        list.push_back(number);
        number++;
    }

    for(int i = 0; i < 10; i++)
        printf("Number: %d\n", list[i]);

    for(const auto& it : list)
        printf("Number: %d\n", it);

    return 0;
}

int reserve_test()
{
    std::vector<int> tab;
    int n = 10;

    tab.reserve(n);

    for(int i = 0; i < n; i++)
        tab.emplace_back(i);

    for(const auto& it : tab)
        printf("Number: %d\n", it);

    printf("First value: %d\n", tab.front());
    printf("Last value: %d\n",tab.back());

    tab.insert(tab.begin() + 5, n);
    tab.erase(tab.begin() + 5);

    tab.clear();

    tab.insert(tab.begin(), n);
    tab.erase(tab.begin());

    return 0;

}

int clear()
{
    std::vector<double> tab;

    double value = 5;

    for(double i = 0; i < 10; i++)
        tab.push_back(value);

    if(tab.empty() == false){
        printf("Vector is not empty.\n");
        tab.clear();
    }

    for(double i = 0; i < 10; i++)
        tab.push_back(value);
    
    for(auto& i : tab)
        printf("Number: %lf ", i);

    tab.pop_back();
    tab.pop_back();

    tab.shrink_to_fit();

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
    clear();

#if defined(__unix__)|| defined(__APPLE__)
    clock_gettime(CLOCK_MONOTONIC, &end);
    double ns_time = ((end.tv_sec - start.tv_sec) * 1e9 +
                         (end.tv_nsec - start.tv_nsec)) / (double)N;

    printf("%.4f ns/op\n", ns_time);
#endif

    return 0;
}
