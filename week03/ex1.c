#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(int age) {
    const int now = 2022;

    return now - age;
}

void memset_int(int* memptr, int val, int num) {
    for (int i = 0; i < num; i++) {
        memptr[i] = val;
    }
    
}

int main() {
    const int size = 5;
    const int x = 10;
    const int* const q = &x;

    int* p = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        printf("%p ", p + i);
    }
    printf("\n");

    memset_int(p, x, size);

    for (int i = 0; i < size; i++) {
        scanf("%d", p + i);
    }

    for (int i = 0; i < size; i++) {
        p[i] = foo(p[i]);
        printf("%d ", p[i]);
    }
}