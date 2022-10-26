#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void main() {
    long long size = 10 * 1024 * 1024;
    int n = 10;
    char* all[10];

    for (size_t i = 0; i < n; i++) {
        all[i] = (char*) malloc(size);
        memset(all[i], 0, size);
        sleep(1);
    }

    for (size_t i = 0; i < n; i++) {
        free(all[i]);
    }
    

    /*
        Ex2:

        I ran this program 2 times (with 10mb and 300mb).
        The amount of free memory decreased by 10mb and 300mb every second.
        si and so were 0 all the time.
    */

    /*
        Ex3:

        I ran this program and found that both VIRT and RES values 
        grew on amount of allocated memory.
    */
    
}