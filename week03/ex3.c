#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//<WRITE YOUR CODE HERE>

#define MAX_NAME_SIZE 63
#define MAX_DATA_SIZE 1024
#define MAX_FILES 256
#define MAX_SUBDIRS 8
#define MAX_PATH 2048

int FILES_COUNTER;
long long NAIVE_ID_COUNTER;

void content_too_long_err() {
    printf("Content is too long, MAX_DATA_SIZE = %d", MAX_DATA_SIZE);
}

void nullptr_err(char* target) {
    printf("Failed to %s due to nullptr \n", target);
}

void file_limit_err() {
    printf("There are too many files, MAX_FILES = %d", MAX_FILES);
}

void dir_limit_err() {
    printf("There are too many directories, MAX_SUBDIRS = %d", MAX_SUBDIRS);
}

struct Directory;
struct File;

typedef struct Directory Directory;
typedef struct File File;

struct File{
    int id;
    int size;
    char name[MAX_NAME_SIZE];
    char data[MAX_DATA_SIZE];
    
    struct Directory * directory;// The parent directory
};

struct Directory{
    int nf;
    int nd;
    
    File* files[MAX_FILES];
    Directory* directories[MAX_SUBDIRS];

    char path[MAX_PATH];
};


// Operations on files
void add_to_file(File *file, const char * content);
void append_to_file(File *file, const char * content);
void pwd_file(File * file);


// Operations on directories
void add_file(File* file, Directory *dir);
void add_dir(Directory *dir1, Directory *dir2); // given to you

// Helper functions
void show_dir(Directory *dir);
void show_file(File *file);
void show_file_detailed(File *file);

File* make_file(char* name, Directory* dir);
Directory* make_dir(char* name, Directory* parent);

int main(){
    
    char content1[] = "int printf(const char * format, ...);";
    char content2[] = "int main(){printf('Hello World');}";
    char content3[] = "//This is a comment in C language";
    char content4[] = "Bourne Again Shell!";

    Directory* root = make_dir("", NULL);
    Directory* home = make_dir("home", root);
    Directory* bin = make_dir("bin", root);
    
    // Add subdirectories
    add_dir(home, root);
    add_dir(bin, root);
    
    File* bash = make_file("bash", root);
    File* ex31 = make_file("ex3_1.c", root);
    File* ex32 = make_file("ex3_2.c", root);
    
    add_file(bash, bin);
    add_file(ex31, home);
    add_file(ex32, home);

    add_to_file(ex31, content1);
    add_to_file(ex32, content3);
    add_to_file(bash, content4);

    append_to_file(ex31, content3);

    pwd_file(bash);
    pwd_file(ex31);
    pwd_file(ex32);

    show_file_detailed(ex31);
    show_file(ex32);
    show_file(bash);
    
    return EXIT_SUCCESS;
}

// Helper functions

// Displays the content of the Directory dir
void show_dir(Directory *dir){
    if (dir)
    {
        printf("\nDIRECTORY\n");
        printf(" path: %s\n", dir->path);
        printf(" files:\n");
        printf("    [ ");
        for (int i = 0; i < dir->nf; i++){
            show_file(dir->files[i]);
        }
        printf("]\n");
        printf(" directories:\n");
        printf("    { ");
        
        for (int i = 0; i < dir->nd; i++){
            show_dir(dir->directories[i]);
        }
        printf("}\n");
        return;
    }
    nullptr_err("show directory");
    
}

// Prints the name of the File file
void show_file(File *file){
    if (file) {
        printf("%s\n", file->name);
        return;
    }
    nullptr_err("show file");
    
}

// Shows details of the File file
void show_file_detailed(File *file){
    if (file) {
        printf("\nFILE\n");
        printf(" id: %d\n", file->id);
        printf(" name: %s\n", file->name);
        printf(" size: %lu\n", file->size);
        printf(" data:\n");
        printf("    [ %s ]\n", file->data);
        return;
    }
    nullptr_err("show file");
}

File* make_file(char* name, Directory* dir) {
    File* file = malloc(sizeof(File));
    
    file->id = NAIVE_ID_COUNTER++;
    if (name) {
        strcpy(file->name, name);
    } else {
        nullptr_err("set name");
        strcpy(file->name, "sus_file");
    }
    
    file->size = 0;

    if (dir) {
        file->directory = dir;
    } else {
        nullptr_err("set directory");
        free(file);
        file->directory = NULL;
    }

    return file;
}

Directory* make_dir(char* name, Directory* parent) {
    Directory* dir = malloc(sizeof(Directory));
    
    if (parent){
        strcpy(dir->path, parent->path);
    } else {
        strcpy(dir->path, "/");
    }

    if (strlen(dir->path) + strlen(name) < MAX_PATH + 1){
        if (dir->path[strlen(dir->path) - 1] != '/') {
            strcat(dir->path, "/");
        }
        strcat(dir->path, name);
    } else {
        content_too_long_err();
        free(dir);
        return NULL;
    }
    
    dir->nf = 0;
    dir->nd = 0;

    return dir;
    
}

// Implementation: Operations on files

// Adds the content to the File file
void add_to_file(File *file, const char * content) {

    if (file && content) {
        if (strlen(content) < MAX_DATA_SIZE) {
            memset(file->data, 0, MAX_DATA_SIZE);
            strcpy(file->data, content);
            file->size = strlen(file->data);
        } else {
            content_too_long_err();
        }
        return;
    } else {
        nullptr_err("add to file");
    }
}

// Appends the content to the File file
void append_to_file(File *file, const char * content) {
	if (file && content) {
        if (file->size + strlen(content) < MAX_DATA_SIZE) {
            strcat(file->data, content);
            file->size = strlen(file->data);
        } else {
            content_too_long_err();
        }
        return;
    }
    nullptr_err("append to file");
}

// Prints the path of the File file
void pwd_file(File * file) {
    if (file) {
        if (file->directory) {
            printf("%s\n", file->directory->path);
        } else {
            printf("/\n");
        }
        return;
    }
    nullptr_err("print directory");
}


// Implementation: Operations on directories

// Adds the File file to the Directory dir
void add_file(File* file, Directory *dir) {
    if (file && dir) {
        if (FILES_COUNTER < MAX_FILES) {
            dir->files[dir->nf] = file;
            file->directory = dir;
            dir->nf++;
            FILES_COUNTER++;
        } else {
            file_limit_err();
        }
        return;
    }
    nullptr_err("add file");
}

// Given to you
// Adds the subdirectory dir1 to the directory dir2
void add_dir(Directory *dir1, Directory *dir2){
	if (dir1 && dir2) {
        if (dir2->nd < MAX_SUBDIRS) {
            dir2->directories[dir2->nd] = dir1;
		    dir2->nd++;
        } else {
            dir_limit_err();
        }
        return;
	}
    nullptr_err("add directory");
}