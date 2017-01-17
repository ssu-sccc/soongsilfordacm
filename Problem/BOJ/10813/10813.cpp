#include <stdio.h>
#include <algorithm>

int arr[110];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		arr[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		std::swap(arr[a], arr[b]);
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}