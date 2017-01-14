#include <stdio.h>
#include <algorithm>

int arr[1000010];

int main(void)
{
	int n, i;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", arr + i);

	std::sort(arr, arr + n);

	for (i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}