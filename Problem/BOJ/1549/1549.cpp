#include <stdio.h>
#include <set>
#include <limits.h>
#include <algorithm>

std::set<long long> set;
long long sum[3010];

long long abss(long long num) {
	if (num < 0) return -num;
	return num;
}

int main(void) {
	int n;
	long long min1 = LLONG_MAX / 2, index;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		long long a;
		scanf("%lld", &a);
		sum[i] = sum[i - 1] + a;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n - k + 1; i++) {
			long long val = sum[i + k - 1] - sum[i - 1];
			if (set.size() != 0) {
				auto it = set.lower_bound(val);
				if (it == set.begin()) {
					if (abss(*it - val) <= min1) {
						min1 = abss(*it - val);
						index = k;
					}
				}
				else if (it == set.end()) {
					if (abss(*std::prev(it) - val) <= min1) {
						min1 = abss(*std::prev(it) - val);
						index = k;
					}
				}
				else {
					if (std::min(abss(*it - val), abss(*std::prev(it) - val)) <= min1) {
						min1 = std::min(abss(*it - val), abss(*std::prev(it) - val));
						index = k;
					}
				}
			}
			if (i - k >= 0)
				set.insert(sum[i] - sum[i - k]);
		}
		set.clear();
	}

	printf("%lld\n%lld\n", index, min1);
}
