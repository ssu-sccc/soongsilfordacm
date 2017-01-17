#include <stdio.h>

int main(void) {
	unsigned long long n, sum = 0;
	scanf("%llu", &n);

	for (int i = 0; i < n; i++)
		sum += i * n + i;

	printf("%llu\n", sum);
}