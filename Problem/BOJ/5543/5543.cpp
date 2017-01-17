#include <stdio.h>

int main(void) {
	int min1 = 2010, min2 = 2010;

	for (int i = 0; i < 3; i++) {
		int a;
		scanf("%d", &a);
		if (min1 > a) min1 = a;
	}
	for (int i = 0; i < 2; i++) {
		int a;
		scanf("%d", &a);
		if (min2 > a) min2 = a;
	}

	printf("%d\n", min1 + min2 - 50);
}