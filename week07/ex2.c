#include <stdio.h>
#include <stdlib.h>

void main() {
    int n;
    printf("N: ");
    scanf("%d", &n);

    int* arr = (int*) malloc(n * sizeof(int));

    for (size_t i = 0; i < n; i++) {
        arr[i] = i;
    }

    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    free(arr);
    
}