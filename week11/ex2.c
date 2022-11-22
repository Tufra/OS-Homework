#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>

void main() {

    DIR* dir;
    struct dirent* dp;
    
    if ((dir = opendir("/")) == NULL) {
        printf("Could not open dir");
        return;
    }
    
    while ((dp = readdir(dir)) != NULL) {
        printf("%s\n", dp->d_name);
    }
    
    closedir(dir);
}