#include <stdio.h>

int main(void) {
    long long s, r = 1;
    scanf("%lld", &s);
    
    while(1) {
        if(r * (r + 1) / 2 > s)
            break;
        r++;
    }
    
    printf("%lld\n", r - 1);
}