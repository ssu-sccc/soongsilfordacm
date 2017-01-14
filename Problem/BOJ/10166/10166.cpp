#include <stdio.h>

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	int d1, d2, r = 1;
	scanf("%d %d", &d1, &d2);

	for (int i = d1; i <= d2; i++) {
		for (int j = 1; j < i; j++) {
			int divisor = i / gcd(j, i);

			if (i / divisor - (d1 - 1) / divisor == 1)
				r++;
		}
	}
	printf("%d\n", r);
}