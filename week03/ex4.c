#include <stdio.h>
#include <stdlib.h>

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)) {
    if (size == sizeof(int)) {
        int* agg = malloc(sizeof(int));

        for (size_t i = 0; i < n; i++) {
            agg = opr(agg, ((int*)base) + i);
        }

        if (opr == &int_sum_mean){ // ??????????????????????????????????????????????
            *agg /= n;
        }

        return agg;
    } 
    if (size == sizeof(double))
    {
        double* agg = malloc(sizeof(double));

        for (size_t i = 0; i < n; i++) {
            agg = opr(agg, ((double*)base) + i);
        }

        if (opr == &double_sum_mean){ // ???????????????????????????????????????//
            *agg /= n;
        }
        
        return agg;
    }

    return NULL;
    
}

int* int_sum(const int* a, const int* b) {
    int* c = malloc(sizeof(int));
    *c = *a + *b;

    return c;
}

int* int_sum_mean(const int* a, const int* b) {
    int* c = malloc(sizeof(int));
    *c = *a + *b;

    return c;
}

double* double_sum(const double* a, const double* b) {
    double* c = malloc(sizeof(double));
    *c = *a + *b;

    return c;
}

double* double_sum_mean(const double* a, const double* b) {
    double* c = malloc(sizeof(double));
    *c = *a + *b;

    return c;
}

void main() {
    double d[5] = {1.5, -0.5, 2.5, 0.1, 3.0};
    int i[5] = {1, 2, 3, 4, 5};

    int i_init = 0;
    double d_init = 0.0;

    int* i_res = aggregate(i, sizeof(int), 5, &i_init, &int_sum);
    printf("%d\n", *i_res);

    double* d_res = aggregate(d, sizeof(double), 5, &d_init, &double_sum);
    printf("%f\n", *d_res);


}