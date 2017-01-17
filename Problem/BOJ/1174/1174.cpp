#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<long long> v;

long long pow(long long idx) {
	long long r = 1;
	for (long long i = 1; i <= idx; i++)
		r *= 10;
	return r;
}

void func(long long digits, long long idx, long long num) {
	v.push_back(num);
	for (long long i = digits + 1; i <= 9; i++)
		func(i, idx + 1, num + pow(idx) * i);
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i <= 9; i++)
		func(i, 1, i);

	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());

	if (n > v.size())
		printf("-1\n");
	else
		printf("%lld\n", v[n - 1]);
	return 0;
}