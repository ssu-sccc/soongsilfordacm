#include <stdio.h>

int main(void) {
	int n, zero = 0, one = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1)
			one++;
		else
			zero++;
	}
	if (one < zero)
		printf("Junhee is not cute!");
	else
		printf("Junhee is cute!");
}