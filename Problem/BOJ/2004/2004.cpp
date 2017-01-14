#include <stdio.h>
#include <algorithm>

long long check5(long long num) {
	if (num < 5)
		return 0;
	return num / 5 + check5(num / 5);
}

long long check2(long long num) {
	if (num < 2)
		return 0;
	return num / 2 + check2(num / 2);
}

int main(void) {
	long long a, b;
	scanf("%lld %lld", &a, &b);

	long long result2 = check2(a) - (check2(b) + check2(a - b)), result5 = check5(a) - (check5(b) + check5(a - b));
	printf("%lld\n", std::min(result2, result5));
	return 0;
}