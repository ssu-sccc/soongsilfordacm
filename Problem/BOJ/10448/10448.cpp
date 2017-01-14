#include <stdio.h>

int dp[45];

int main(void) {
	dp[1] = 1;
	int test, c = 2;
	for (int i = 2; i <= 44; i++)
		dp[i] = dp[i - 1] + c++;

	scanf("%d", &test);

	for (int t = 0; t < test; t++) {
		bool flag = false;
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= 44 && !flag; i++)
			for (int j = i; j <= 44 && !flag; j++)
				for (int k = j; k <= 44 && !flag; k++)
					if (dp[i] + dp[j] + dp[k] == n)
						flag = true;

		printf("%d\n", flag);
	}
}