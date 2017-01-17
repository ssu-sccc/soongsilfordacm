#include <stdio.h>

int main(void)
{
	int a, b, c, d;
	int second;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	second = a + b + c + d;
	printf("%d\n%d\n", second / 60, second % 60);
	return 0;
}