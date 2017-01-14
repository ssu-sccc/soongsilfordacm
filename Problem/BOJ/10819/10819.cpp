#include <stdio.h>
#include <algorithm>
#include <math.h>

int n, arr[10], check[10], result[10], r;

void func(int idx) {
	if (idx == n)
	{
		int sum = 0;
		for (int i = 0; i < n - 1; i++)
			sum += abs(result[i] - result[i + 1]);
		r = std::max(r, sum);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i] == 1)
			continue;

		result[idx] = arr[i];
		check[i] = 1;
		func(idx + 1);
		check[i] = 0;
	}
}

int main(void) {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	func(0);
	printf("%d\n", r);
	return 0;
}