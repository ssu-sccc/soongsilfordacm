#include <stdio.h>
 
int result[100], u;
 
void func(int n, int num) {
    u = 0;
    while (n) {
        result[u++] = n % num;
        n /= num;
    }
}
 
int main(void) {
    int test;
    scanf("%d", &test);
    for(int t = 0; t < test; t++) {
    int n, i, j;
        bool flag = false;
    scanf("%d", &n);
 
    for (i = 2; i <= 64; i++) {
        func(n, i);
        for (j = 0; j < u / 2; j++)
            if (result[j] != result[u - j - 1])
                break;
 
        if (j == u / 2)
            flag = true;
    }
        printf("%d\n", flag);
    }
    return 0;
}