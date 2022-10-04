#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

void main() {
    int p[2];

    if (pipe(p) < 0) {
        puts("no pipe?");
        return;
    }
    
    pid_t publisher = fork();
    pid_t subscriber = fork();
    
    if (publisher == 0) {
        char str[1024];

        while (1) {
            fgets(str, 1024, stdin);

            if (write(p[1], str, 1024) < 0) {
                puts("no write?");
                return;
            }
            
        }
        
    }

    if (subscriber == 0) {
        char str[1024];

        while (1) {
            if (read(p[0], str, 1024) > 0) {
                printf("read: %s\n", str);
            }
            
        }
        
    }
    
    wait(NULL);
}