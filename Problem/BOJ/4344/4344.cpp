#include <stdio.h>

int arr[1010];

int main(void) {
	int test;
	scanf("%d", &test);

	for (int t = 0; t < test; t++) {
		int n, sum = 0, cnt = 0;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
			sum += arr[i];
		}

		double avg = sum / (double)n;
		for (int i = 0; i < n; i++)
			if (arr[i] > avg)
				cnt++;

		printf("%.3lf%%\n", cnt / (double)n * 100);
	}
}