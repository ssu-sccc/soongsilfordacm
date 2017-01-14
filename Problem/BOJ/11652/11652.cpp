#include <stdio.h>
#include <algorithm>
#include <limits.h>

long long arr[1000010];

int main(void) {
	int n, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%lld", arr + i);

	std::sort(arr, arr + n);

	int cnt = 1, max1 = 1;
	long long num = arr[0], result = arr[0];
	arr[n] = LLONG_MAX - 1;
	for (i = 1; i <= n; i++) {
		if (arr[i] != num)
		{
			if (cnt > max1)
				max1 = cnt, result = arr[i - 1];
			cnt = 1;
			num = arr[i];
		}
		else
			cnt++;
	}


	printf("%lld\n", result);
	return 0;
}