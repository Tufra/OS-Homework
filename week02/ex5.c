#include <stdio.h>

int tribonacci(int n) {

    if (n < 0 || n > 37)
    {
        printf("illegal n");
        return 0;
    }
    

    int a = 0;
    int b = 1;
    int c = 1;
    int d = 0;

    if (n == 0) {
        return a;
    } else if (n == 1 || n == 2) {
        return b;
    }
    
    for (int i = 3; i <= n; i++) {
        d = c + b + a;
        a = b;
        b = c;
        c = d;
    }

    return d;
}

int main() {
    int num = 0;
    // scanf("%d", &num);

    printf("%d %d", tribonacci(4), tribonacci(36));
}