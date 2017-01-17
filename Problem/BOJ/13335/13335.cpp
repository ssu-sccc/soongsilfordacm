#include <stdio.h>
int arr[1010], bridge[110];
int main(void) {
	int n, w, l, r = 1, index = 1;
	scanf("%d %d %d", &n, &w, &l);
	for (int i = 1; i <= n; i++)
		scanf("%d", arr + i);
	while (1) {
		int sum = 0;
		for (int i = 1; i <= w; i++)
			bridge[i] = bridge[i + 1], sum += bridge[i];
		if (index == n + 1 && sum == 0)
			break;
		if (n >= index && sum + arr[index] <= l)
			bridge[w] = arr[index++];
		r++;
	}
	printf("%d\n", r);
} 