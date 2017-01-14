#include <stdio.h>
#include <string.h>

char arr[1010][110];

int main(void) {
	int n;
	while (1) {
		scanf("%d", &n);
		getchar();
		if (n == 0)
			break;
		memset(arr, 0, sizeof(arr));

		for (int i = 1; i <= n; i++) {
			char c;
			int idx = 1;
			while ((c = getchar()) != '\n')
				arr[i][idx++] = c;
		}
		int row = 1, col = 1;
		while (1) {
			if (row > n)
				break;
			if (arr[row][col] == ' ' || arr[row][col] == 0)
				row++;
			else
				col++;
		}

		printf("%d\n", col);
	}
}