#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define path "/tmp/ex1"

void main() {
    
    int fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        puts("no open?");
        return;
    }
    

    puts("this is subscriber");
    char str[1024];

    while (1) {
        if (read(fd, str, 1024) > 0) {
            printf("read: %s\n", str);
        }

        sleep(1);
    }
    
}