#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <malloc.h>
#include <string.h>

#define MAX_LINKS_NUMBER 64

typedef struct {
    ino_t inode_number;
    char** link_filenames;
    int links_found;
} Record;

void main() {

    DIR* dir;
    struct dirent* dp;
    struct stat* st;
    char dir_name[32] = "./tmp/\0";

    int records_size = 0;
    Record* records;

    if ((dir = opendir("./tmp")) == NULL) {
        printf("Could not open dir");
        return;
    }
    while ((dp = readdir(dir)) != NULL) {
        char* full_path = strcat(strdup(dir_name), dp->d_name);
        int ret = stat(full_path, st);

        if (ret != 0) {
            printf("Could not use stat on %s\n (%s)", full_path, strerror(ret));
            closedir(dir);
            return;
        }

        if (st->st_nlink >= 2) {
            int found = 0;

            for (size_t i = 0; i < records_size; i++) {
                if (records[i].inode_number == st->st_ino) {

                    records[i].links_found++;
                    records[i].link_filenames[records[i].links_found - 1] = dp->d_name;
                    found = 1;
                }
            }

            if (found == 0) {
                records_size++;
                records = (Record*) realloc(records, (records_size) * sizeof(Record));

                records[records_size - 1].inode_number = st->st_ino;
                records[records_size - 1].link_filenames = malloc(MAX_LINKS_NUMBER * sizeof(char*));
                records[records_size - 1].link_filenames[0] = dp->d_name;
                records[records_size - 1].links_found = 1;
            }
              
        }

        free(full_path);
        
    }

    printf("File - Hard Links\n");

    for (size_t i = 0; i < records_size; i++) {
        printf("%s - ", records[i].link_filenames[0]);
        for (size_t j = 0; j < records[i].links_found - 1; j++) {
            printf("%s, ", records[i].link_filenames[j]);
        }
        printf("%s\n", records[i].link_filenames[records[i].links_found - 1]);
    }

    closedir(dir);
    free(records);
}