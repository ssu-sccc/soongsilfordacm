#include <stdio.h>
#include <algorithm>

int main(void) {
	double r;
	int a, b, n;

	scanf("%d %d", &a, &b);
	r = 1000.0 / b * a;
	
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a, &b);
		r = std::min(r, 1000.0 / b * a);
	}

	printf("%.2lf\n", r);
}