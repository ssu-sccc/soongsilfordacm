#include <stdio.h>

int main(void) {
	long long n, i = 1, sum = 1;
	scanf("%lld", &n);
	
	while (1) {
		if (sum > n)
			break;
		i++;
		sum += 2 * i * i - 2 * i + 1;
		
	}
	printf("%lld\n", i - 1);
}