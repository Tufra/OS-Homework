#include <stdio.h>
#include <string.h>
#include <ctype.h>

void tolower_str(char* str, int len) {
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

int count(char* str, char c) {
    int counter = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            counter++;
        }
    }

    return counter;    
}

void countAll(char* str) {
    int len = strlen(str);

    tolower_str(str, len);
    

    for (int i = 0; i < len; i++) {
        printf("%c:%d", str[i], count(str, str[i]));

        if (i != len - 1) {
            printf(", ");
        }
        
    }
    
}

int main() {
    char buff[256];
    scanf("%s", buff);

    countAll(buff);
}