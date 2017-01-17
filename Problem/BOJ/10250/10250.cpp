#include <stdio.h>

long long hotel(int h, int w, int n)
{
        int f, a;

        f = (n - 1) / h;

        a = n % h;

        if(a == 0) a = h;

        return (a * 100) + f + 1;
}

int main(void)
{
        int n, i;
        long long result[1000] = {0};
        int H, W, N;
        scanf("%d", &n);

        for(i = 0; i < n; i++)
        {
                scanf("%d %d %d", &H, &W, &N);

                result[i] = hotel(H, W, N);
        }

        for(i = 0; i < n; i++)
                printf("%lld\n", result[i]);

        return 0;
}