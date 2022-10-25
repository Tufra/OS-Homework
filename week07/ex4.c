#include <stdlib.h>
#include <malloc.h>

void* realloc(void* ptr, size_t new_size) {
    if (ptr == NULL) {
        if (new_size == 0) {
            // malloc(0) is implementation-defined so it 
            // could be better to explicitly return NULL
            return NULL;
        }
        
        return malloc(new_size);
    }

    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    
    char* ret = malloc(new_size);

    size_t ptr_size = malloc_usable_size(ptr);
    size_t actual_size = ptr_size > new_size ? new_size : ptr_size;

    for (char i = 0; i < actual_size; i++) {
        ret[i] = ((char*)ptr)[i];
    }
    
    free(ptr);
    return (void*)ret;
    
}

void main() {
    int* arr = (int* )malloc(5 * sizeof(int));

    printf("%d\n", malloc_usable_size((void*)arr));

    for (size_t i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    

    for (size_t i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    arr = (int*)realloc((void*)arr, 8);

    for (size_t i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    arr = (int*)realloc((void*)arr, 3);

    for (size_t i = 0; i < 3; i++) {
        printf("%d ", arr[i]);
    }
    
    
    
}