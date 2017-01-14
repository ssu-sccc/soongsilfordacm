#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <vector>

int arr[100010];
std::vector<int> divisor;

int main(void) {
	int n, min1 = INT_MAX / 2;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	
	std::sort(arr, arr + n);

	for (int i = 1; i < n; i++)
		min1 = std::min(min1, arr[i] - arr[i - 1]);

	for (int i = 1; i * i <= min1; i++) {
		if (min1 % i != 0)
			continue;
		divisor.push_back(i);
		if (i * i != min1)
			divisor.push_back(min1 / i);
	}

	int r = 1;
	for (int i = 0; i < divisor.size(); i++) {
		bool flag = true;
		for (int j = 1; j < n && flag; j++)
			if ((arr[j] - arr[0]) % divisor[i] != 0)
				flag = false;

		if (flag)
			r = std::max(r, divisor[i]);
	}

	printf("%d\n", (arr[n - 1] - arr[0]) / r + 1 - n);
}