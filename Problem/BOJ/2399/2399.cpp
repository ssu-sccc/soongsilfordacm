#include <stdio.h>
#include <algorithm>

long long arr[10010];

int main(void)
{
	long long n, i;
	long long result = 0;
	scanf("%lld", &n);

	for(i = 1; i <= n; i++)
		scanf("%lld", arr + i);

	std::sort(arr + 1, arr + n + 1);

	for(i = 1; i <= n - 1; i++)
		result += i * (n - i) * (arr[i + 1] - arr[i]);

	printf("%lld\n", result * 2);
	return 0;
}