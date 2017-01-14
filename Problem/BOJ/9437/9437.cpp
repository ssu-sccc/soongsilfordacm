#include <stdio.h>
#include <algorithm>
#include <string.h>

int main(void) {
	while (1) {
		int n, p;
		scanf("%d", &n);
		if (n == 0)
			break;
		scanf("%d", &p);

		if (p <= n / 2) {
			if (p % 2 == 1)
				printf("%d %d %d\n", p + 1, n - p, n - p + 1);
			else
				printf("%d %d %d\n", p - 1, n - (p - 1), n - (p - 1) + 1);
		}
		else {
			if (p % 2 == 0)
				printf("%d %d %d\n", n - p + 1, n - p + 2, p - 1);
			else
				printf("%d %d %d\n", n - (p + 1) + 1, n - (p + 1) + 2, p + 1);
		}
	}
}