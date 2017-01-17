#include <stdio.h>

char arr[110][110];

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf(" %c", &arr[i][j]);

	int r1 = 0, r2 = 0;
	for (int i = 1; i <= n; i++) {
		int cnt1 = 0, cnt2 = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 'X') {
				if (cnt1 > 1)
					r1++;
				cnt1 = 0;
			}
			else
				cnt1++;

			if (arr[j][i] == 'X') {
				if (cnt2 > 1)
					r2++;
				cnt2 = 0;
			}
			else
				cnt2++;

		}
		if (cnt1 > 1)
			r1++;
		if (cnt2 > 1)
			r2++;
	}
	printf("%d %d\n", r1, r2);
}