#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void dot_product(FILE* shared, double* u, double* v, int batch, int child_i) {
    int offset = child_i * batch;
    double dp = 0.0;

    for (size_t i = offset; i < offset + batch; i++) {
        dp += u[i] + v[i];
    }
    
    fprintf(shared, "%f ", dp);
}

void print_sum(FILE* shared, int n) {
    double res = 0.0;
    double buff = 1.0;

    for (size_t i = 0; i < n; i++) {

        int status = fscanf(shared, "%lf\n", &buff);
        res += buff;
    }
    
    printf("%f", res);
}

void main(int argc, char* argv[]) {
    double u[120];
    double v[120];

    FILE* shared = fopen("temp.txt", "w+");

    int n = atoi(argv[1]);
    srand(time(NULL));

    for (size_t i = 0; i < 120; i++) {
        u[i] = (double)rand() / (double)RAND_MAX * 99.0;
        v[i] = (double)rand() / (double)RAND_MAX * 99.0;
    }
    
    int batch = 120 / n;
    pid_t* children = malloc(sizeof(pid_t) * n);

    for (size_t i = 0; i < n; i++) {
        children[i] = fork();
        if (children[i] == 0) {
            dot_product(shared, u, v, batch, i);
            return;
        }
        
    }
    
    for (size_t i = 0; i < n; i++) {
        wait(children + i);
    }

    fflush(shared);
    rewind(shared);

    print_sum(shared, n);

    fclose(shared);
}