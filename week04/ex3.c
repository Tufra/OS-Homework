#include <unistd.h>
#include <stdlib.h>

void main(int argc, char* argv[]) {
    int n = 3;

    if (argc > 1) {
        n = atoi(argv[1]);
    }

    for (size_t i = 0; i < n; i++) {
        fork();
        sleep(5);
    }
    
    
}