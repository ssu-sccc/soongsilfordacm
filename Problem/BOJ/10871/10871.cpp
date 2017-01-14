#include <stdio.h>

int main(void)
{
    int n, x;
    scanf("%d %d", &n, &x);
    
    for(int i = 0; i < n; i++)
        {
        int a;
        scanf("%d", &a);
        if(a < x)
            printf("%d ", a);
    }
    printf("\n");
    return 0;
}