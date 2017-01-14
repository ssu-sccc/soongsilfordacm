#include <stdio.h>
#include <algorithm>

char str[100];

int main(void) {
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	int i = 0, r = 1;
	while (i < n) {
		r++;
		if (str[i] == 'S')
			i++;
		else
			i += 2;
	}
	printf("%d\n", std::min(r, n));
}