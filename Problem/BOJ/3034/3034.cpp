#include <stdio.h>

int main(void) {
	int n, w, h;
	scanf("%d %d %d", &n, &w, &h);

	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		a *= a;

		if (a <= w * w + h * h)
			printf("DA\n");
		else
			printf("NE\n");
	}
}