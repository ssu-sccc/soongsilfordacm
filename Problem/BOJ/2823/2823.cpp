#include <stdio.h>
#include <string.h>

char arr[12][12];
int move[4][2] = { { 1, 0 },{ 0, 1 },{ -1, 0 },{ 0, -1 } };

int main(void) {
	int n, m, t = 0;
	scanf("%d %d", &n, &m);
	memset(arr, 'X', sizeof(arr));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == '.')
				t++;
		}
	if (t == 1) {
		printf("0\n");
		return 0;
	}
	int r = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int X = 0;
			if (arr[i][j] == 'X')
				continue;
			for (int k = 0; k < 4; k++) {
				int nx = i + move[k][0], ny = j + move[k][1];

				if (arr[nx][ny] == 'X')
					X++;
			}
			if (X >= 3)
				r++;
		}
	}

	if (r >= 1)
		printf("1\n");
	else
		printf("0\n");
}