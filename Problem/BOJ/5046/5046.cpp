#include <stdio.h>
#include <limits.h>
#include <algorithm>

int main(void) {
	int n, b, h, w, min1 = INT_MAX / 2;
	scanf("%d %d %d %d", &n, &b, &h, &w);

	for (int i = 0; i < h; i++) {
		int cost;
		scanf("%d", &cost);

		for (int j = 0; j < w; j++) {
			int a;
			scanf("%d", &a);
			if (a >= n)
				min1 = std::min(min1, n * cost);
		}
	}
	if (min1 > b)
		printf("stay home\n");
	else
		printf("%d\n", min1);
}