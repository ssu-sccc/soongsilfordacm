#include <stdio.h>
#include <limits.h>
#include <algorithm>

int abss(int x) {
	if (x < 0) return -x;
	return x;
}

int main(void) {
	int sum = 0, a, r = 0, diff = INT_MAX / 2;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a);
		sum += a;
		if (abss(100 - sum) < diff) {
			diff = abss(100 - sum);
			r = sum;
		}
		else if (abss(100 - sum) == diff)
			r = std::max(r, sum);
	}

	printf("%d\n", r);
}