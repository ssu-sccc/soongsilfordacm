#include <stdio.h>

bool arr[110][110];

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		for (int i = a; i < a + 10; i++)
			for (int j = b; j < b + 10; j++)
				arr[i][j] = true;
	}
	int result = 0;

	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			result += arr[i][j];

	printf("%d\n", result);
}