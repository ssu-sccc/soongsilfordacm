#include <stdio.h>
#include <algorithm>

int arr[10010], num[10010];

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	std::sort(arr, arr + n);
	int sum = 0;

	for (int i = 1; i < n; i++) {
		num[i - 1] = arr[i] - arr[i - 1];
		sum += num[i - 1];
	}

	std::sort(num, num + n - 1, [](int a, int b) {
		return a > b;
	});

	for (int i = 0; i < k - 1; i++)
		sum -= num[i];

	printf("%d\n", sum);
	return 0;
}