#include <stdio.h>
#include <string.h>
#include <algorithm>

long long pow(int n) {
	long long r = 1;
	for (int i = 0; i < n; i++)
		r *= 10;
	return r;
}

long long reverse(long long n) {
	long long n1 = 0, n2 = 0;
	char arr[12] = { 0 };
	sprintf(arr, "%lld", n);
	int len = strlen(arr);

	for (int i = 0; i < len; i++) {
		n1 += (arr[i] - '0') * pow(len - i - 1);
		n2 += (9 - (arr[i] - '0')) * pow(len - i - 1);
	}
	return n1 * n2;
}

int main(void) {
	int test;
	scanf("%d", &test);

	for (int t = 0; t < test; t++) {
		long long s, e, max1 = 0, c1 = 0, c2 = 0;
		char tmp[12] = { 0 };
		scanf("%lld", &e);
		sprintf(tmp, "%lld", e);

		int len = strlen(tmp);
		if (e < pow(len - 1) * 5)
			max1 = reverse(e);
		else
			max1 = reverse(pow(len - 1) * 5);
		printf("%lld\n", max1);
	}
	return 0;
}