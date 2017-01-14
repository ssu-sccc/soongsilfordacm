#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<int> v;

int main(void) {
	int n, m, prev = 0;
	scanf("%d %d", &n, &m);
	scanf("%d", &prev);
	long long sum = 0;
	for (int i = 1; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a - prev);
		sum += a - prev;
		prev = a;
	}
	std::sort(v.begin(), v.end());

	for (int i = v.size() - 1; i >= 0; i--) {
		if (m == 1)
			break;
		sum -= v[i];
		m--;
	}
	printf("%lld\n", sum);
}