#include <stdio.h>

int main(void) {
	for (int t = 0; t < 3; t++) {
		int a = 0, b = 0;
		for (int i = 0; i < 4; i++) {
			int c;
			scanf("%d", &c);
			if (c == 0)
				a++;
			else
				b++;
		}

		if (a == 1 && b == 3)
			printf("A\n");
		if (a == 2 && b == 2)
			printf("B\n");
		if (a == 3 && b == 1)
			printf("C\n");
		if (a == 4)
			printf("D\n");
		if (b == 4)
			printf("E\n");
	}
}