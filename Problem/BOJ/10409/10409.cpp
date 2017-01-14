#include <stdio.h>

int main(void) {
	int n, t, sum = 0, r;

	scanf("%d %d", &n, &t);
	r = n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		sum += a;
		if (sum <= t)
			ans++;
	}
	printf("%d\n", ans);
}