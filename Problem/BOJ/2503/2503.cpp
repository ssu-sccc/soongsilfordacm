#include <stdio.h>

struct info {
	int a1, a2, a3;
	int s, b;
};

info arr[110];

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%1d%1d%1d %d %d", &arr[i].a1, &arr[i].a2, &arr[i].a3, &arr[i].s, &arr[i].b);
	int r = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i == j)
				continue;

			for (int k = 1; k <= 9; k++) {
				if (k == j || k == i)
					continue;

				bool flag = true;
				for (int m = 1; m <= n && flag; m++) {
					int s = 0, b = 0;
					if (arr[m].a1 == i)
						s++;
					if (arr[m].a2 == j)
						s++;
					if (arr[m].a3 == k)
						s++;

					if (arr[m].a1 == j || arr[m].a1 == k)
						b++;
					if (arr[m].a2 == i || arr[m].a2 == k)
						b++;
					if (arr[m].a3 == i || arr[m].a3 == j)
						b++;

					if (arr[m].s != s || arr[m].b != b)
						flag = false;
				}
				if (flag)
					r++;
			}
		}
	}

	printf("%d\n", r);
}