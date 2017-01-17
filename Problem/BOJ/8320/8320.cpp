#include <stdio.h>

int main(void) {
	long long n;
	long long result = 0;
	scanf("%lld", &n);

	for (long long i = 1; i <= n; i++) {

		if (i * i > n)
			break;

		result += n / i - i + 1;
	}

	printf("%lld\n", result);
	return 0;
}