#include <stdio.h>

int main(void) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int cur = n + m, r = 0;
    
    while(cur / k) {
        r += cur / k;
        cur = cur / k + cur % k;
    }
    printf("%d\n", r);
}