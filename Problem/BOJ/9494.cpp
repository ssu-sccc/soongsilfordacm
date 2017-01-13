#include <stdio.h>
#include <cstring>

char str[1010][110];

int main() {
	int N, j, i;
	while (1) {
		scanf("%d", &N);
		getchar();
		if (!N)
			break;

		memset(str, 0, sizeof(char) * 1010 * 110);

		for (i = 0; i < N; ++i) {
			scanf("%[^\n]", str[i]);
			getchar();
		}

		j = 0;
		for (i = 0; i < 100; ++i) {
			if (str[j][i] == ' ' || str[j][i] == '\0') {
				j++;
				i--;
			}
			if (j == N)
				break;
		}
		printf("%d\n", i + 2);
	}
	return 0;
}
