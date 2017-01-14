#include <algorithm>
#include <stdio.h>

int arr[1010];

int main(void) {
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		scanf("%d", arr + i);

	std::sort(arr + 1, arr + n + 1);
	for(int i = 1; i <= n; i++)
		printf("%d\n", arr[i]);
}