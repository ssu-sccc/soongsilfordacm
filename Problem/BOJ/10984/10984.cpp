#include <stdio.h>

int main(void) {
	int test;
	scanf("%d", &test);

	for (int t = 0; t < test; t++) {
		int n, s = 0;
		scanf("%d", &n);
		double sum = 0;
		for (int i = 0; i < n; i++) {
			int a;
			double b;
			scanf("%d %lf", &a, &b);
			sum += a * b;
			s += a;
		}
		printf("%d %.1lf\n", s, sum / s);
	}
}