#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <cmath>

long long x[30], y[30], min_x, n, sx, sy;

void func1(int num, long long sum1, long long sum2, int t) {
	if (t == 0) {
		min_x = std::min(min_x, (sx - 2 * sum1) * (sx - 2 * sum1) + (sy - 2 * sum2) * (sy - 2 * sum2));
		return;
	}
	if (num == n + 1)
		return;

	func1(num + 1, sum1, sum2, t);
	func1(num + 1, sum1 + x[num], sum2 + y[num],  t - 1);
}

int main(void) {
	int test;
	scanf("%d", &test);

	for (int t = 0; t < test; t++) {
		scanf("%lld", &n);
		sx = sy = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld %lld", x + i, y + i);
			sx += x[i];
			sy += y[i];
		}

		min_x = LLONG_MAX / 2;
		func1(1, 0, 0, n / 2);
		printf("%.6lf\n", std::sqrt(min_x));
	}
}