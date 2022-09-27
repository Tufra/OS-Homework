#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

void main() {
    clock_t main_start = clock();

    pid_t first_child = fork();
    clock_t first_child_start = clock();
    if (first_child == 0) {

        printf("first child (%d) (parent %d) time %.10fs \n", getpid(), getppid(), ((float)(clock() - first_child_start)) / CLOCKS_PER_SEC * 1000);
        return;
    }

    pid_t second_child = fork();
    clock_t second_child_start = clock();
    if (second_child == 0) {

        printf("second child (%d) (parent %d) time %.10fs \n", getpid(), getppid(), ((float)(clock() - second_child_start)) / CLOCKS_PER_SEC * 1000);
        return;
    }

    wait(&first_child);
    wait(&second_child);
    printf("main (%d) (parent %d) time %.10fs \n", getpid(), getppid(), ((float)(clock() - main_start)) / CLOCKS_PER_SEC * 1000);
}