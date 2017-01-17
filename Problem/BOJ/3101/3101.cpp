#include <stdio.h>

long long n;
long long upper[100010], lower[100010];

long long getVal(long long x, long long y) {
	if (x + y <= 1 + n) {
		if ((x + y) % 2 == 1)
			return upper[y + x - 1] + (x - 1);
		else
			return upper[y + x - 1] - (x - 1);
	}
	else {
		if ((x + y) % 2 == 1)
			return lower[y - (n - x)] - (n - x);
		else
			return lower[y - (n - x)] + (n - x);
	}
}

int main(void) {
	int k;
	scanf("%lld %d", &n, &k);
	getchar();
	
	upper[1] = 1, upper[2] = 2;
	lower[n] = n * n, lower[n - 1] = n * n - 1;
	long long var = 5;
	for (long long i = 3; i <= n; i += 2, var += 4) {
		upper[i] = upper[i - 2] + var;
		upper[i + 1] = upper[i - 1] + var;
		lower[n - i] = lower[n - i + 2] - var;
		lower[n - i + 1] = lower[n - i + 3] - var;
	}

	long long x = 1, y = 1, r = 1;
	for (int i = 0; i < k; i++) {
		char c = getchar();
		if (c == 'U')
			x--;
		else if (c == 'D')
			x++;
		else if (c == 'L')
			y--;
		else
			y++;

		r += getVal(x, y);
	}
	printf("%lld\n", r);
}