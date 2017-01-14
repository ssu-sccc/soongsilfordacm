#include <stdio.h>

char str[60];

int main(void) {
	scanf("%s", str);
	int r = 10;
	for (int i = 1; str[i] != '\0'; i++) {
		if (str[i] == str[i - 1])
			r += 5;
		else
			r += 10;
	}
	printf("%d\n", r);
}