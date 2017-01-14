#include <stdio.h>
#include <string.h>

char str[120];
char word[8][4] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main(void) {
	int r = 0, i = 0;
	scanf("%s", str);
	while (str[i] != '\0') {
		int plus = 1;
		for (int j = 0; j < 8; j++) {
			if (strncmp(str + i, word[j], strlen(word[j])) == 0) {
				plus = strlen(word[j]);
				break;
			}
		}

		r++;
		i += plus;
	}
	printf("%d\n", r);
}