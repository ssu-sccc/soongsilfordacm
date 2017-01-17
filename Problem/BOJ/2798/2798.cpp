#include <stdio.h>

int arr[110];

int main(void) {
	int n, m, sum = 0;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%d", arr + i);

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (arr[i] + arr[j] + arr[k] > m)
					continue;
				if (sum < arr[i] + arr[j] + arr[k])
					sum = arr[i] + arr[j] + arr[k];
			}
		}
	}
	printf("%d\n", sum);
}