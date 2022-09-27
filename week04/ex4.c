#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void main() {
    if (system(NULL) == 0) {
        printf("shell is unavailable");
        return;
    }

    char command[256];
    char* quit = "exit\n";
    printf("> ");
    fgets(command, 256, stdin);

    while (strcmp(command, "exit\n") != 0) {
        system(command);

        printf("> ");
        fgets(command, 256, stdin);
    }
    
}