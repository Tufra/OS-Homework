#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

typedef struct Thread {
    int i;
    pthread_t id;
    char message[256];
} Thread;

void* print(void* arg) {
    printf("%s", ((Thread*)arg)->message);
    return NULL;
}

void main(int argc, char* argv[]){

    int n = atoi(argv[1]);

    Thread* threads = malloc(n * sizeof(Thread));

    for (size_t i = 0; i < n; i++) {
        threads[i].i = i;
        sprintf(threads[i].message, "this is thread %d\n", i);

        pthread_create(&((threads + i)->id), NULL, print, (void *)(threads + i));
        printf("%s %d %s\n", "thread ", i, " created");
        pthread_join(threads[i].id, NULL);
        printf("%s %d %s\n", "thread ", threads[i].i, " destroyed");
    }
    
}