#include <stdio.h>

int main(void) {
	int test;
	scanf("%d", &test);

	for (int t = 0; t < test; t++) {
		int h, m, s, d, xh, xm, xs, xd;

		scanf("%d %d %d %d %d %d %d %d", &h, &m, &s, &d, &xh, &xm, &xs, &xd);
		h = h + xh, m = m + xm, s = s + xs, d = d + xd;

		if (h <= 1)
			h = 1;
		if (m <= 1)
			m = 1;
		if (s <= 0)
			s = 0;
		printf("%d\n", h * 1 + m * 5 + s * 2 + 2 * d);
	}
	return 0;
}