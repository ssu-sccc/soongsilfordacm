#include <stdio.h>
#include <algorithm>

int main(void) {
	int n, result = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		result += std::max(0, (n - i) / 2 - std::max(i, n / 2 - i + 1) + 1);
	printf("%d\n", result);
}