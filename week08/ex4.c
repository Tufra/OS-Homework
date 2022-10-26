#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

void main() {
    long long size = 10 * 1024 * 1024;
    int n = 10;
    char* all[10];

    struct rusage val;

    for (size_t i = 0; i < n; i++) {
        all[i] = (char*) malloc(size);
        memset(all[i], 0, size);
        
        int res = getrusage(RUSAGE_SELF, &val);
        if (res == 0) {
            printf("ru_maxrss: %ld\n", val.ru_maxrss);
        }
        
        sleep(1);
    }

    for (size_t i = 0; i < n; i++) {
        free(all[i]);
    }
    
}