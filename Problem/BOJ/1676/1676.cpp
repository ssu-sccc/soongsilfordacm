#include <stdio.h>
#include <algorithm>

int main(void) {
	int n, two = 0, five = 0;
	scanf("%d", &n);

	for (int i = 2; i <= n; i *= 2)
		two += n / i;
	
	for (int i = 5; i <= n; i *= 5)
		five += n / i;

	printf("%d\n", std::min(two, five));
}