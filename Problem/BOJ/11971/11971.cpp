#include <stdio.h>
#include <algorithm>

int arr[110];

int main(void) {
	int n, m, prev = 0, max1 = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		for (int j = prev + 1; j <= prev + a; j++)
			arr[j] = b;
		prev += a;
	}

	prev = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		for (int j = prev + 1; j <= prev + a; j++)
			max1 = std::max(max1,b - arr[j]);
		prev += a;
	}
	printf("%d\n", max1);
}