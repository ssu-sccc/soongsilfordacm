#include <stdio.h>
#include <string.h>

char str[20][50];
bool check[20];
int n;

int change(char c) {
	if (c == 'R')
		return 0;
	else if (c == 'S')
		return 1;
	else
		return 2;
}

void erase(int idx, char c) {
	for (int i = 1; i <= n; i++)
		if (str[i][idx] == c)
			check[i] = true;
}

int main(void) {
	int test;
	scanf("%d", &test);

	for (int t = 0; t < test; t++) {
		memset(check, false, sizeof(check));
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
			scanf("%s", str[i]);
		int k = strlen(str[1]), cnt, index;

		for (int i = 0; i < k; i++) {
			int num[3] = { 0 };
			cnt = 0;
			for (int j = 1; j <= n; j++) {
				if (check[j])
					continue;
				num[change(str[j][i])]++;
				cnt++;
			}
			if (cnt <= 1)
				break;

			if (num[0] && num[1] && !num[2]) // 0ÀÌ R 1ÀÌ S 2°¡ P
				erase(i, 'S');
			else if (num[0] && !num[1] && num[2])
				erase(i, 'R');
			else if (!num[0] && num[1] && num[2])
				erase(i, 'P');
		}

		cnt = 0;
		for (int i = 1; i <= n; i++)
			if (!check[i])
				cnt++, index = i;

		if (cnt == 1)
			printf("%d\n", index);
		else
			printf("0\n");
	}
}