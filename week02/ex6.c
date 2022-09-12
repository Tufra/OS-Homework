#include <stdio.h>

void print_first_cool_pattern(int h) {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }

        printf("\n");
    }
    printf("\n");
}

void print_second_cool_pattern(int h) {
    if (h % 2 == 1) {
        for (int i = 1; i <= h / 2 + 1; i++) {
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
        
        for (int i = h / 2; i > 0; i--) {
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
        
    } else {
        for (int i = 1; i <= h / 2; i++) {
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
        
        for (int i = h / 2; i > 0; i--) {
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
        
    }
    printf("\n");
}

void print_third_cool_pattern(int h) {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= h; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n = 7;
    
    print_first_cool_pattern(n);
    print_second_cool_pattern(n);
    print_third_cool_pattern(n);
}