#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define path "/tmp/ex1"

void main(int argc, char* argv[]) {
    int res = mkfifo(path, 0777);
    if (res < 0)
    {
        puts(strerror(errno));
    }
    puts("fifo created");
    
    int fd = open(path, O_WRONLY);
    if (fd < 0)
    {
        puts(strerror(errno));
    }
    
    int sub_n = atoi(argv[1]);

    puts("this is publisher");
    char str[1024];

    while (1) {
        fgets(str, 1024, stdin);

        for (size_t i = 0; i < sub_n; i++) {
            write(fd, str, 1024);
        }

        sleep(1);
    }
    
}