#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>

char str[100010];
std::pair<int, int> arr[100010];
std::set<std::pair<int, int>> plus[100010], minus[100010];

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	scanf("%s", str + 1);
	
	std::vector<int> X, Y;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
		X.push_back(arr[i].second - arr[i].first);
		Y.push_back(arr[i].first + arr[i].second);
	}

	std::sort(X.begin(), X.end());
	std::sort(Y.begin(), Y.end());
	X.erase(std::unique(X.begin(), X.end()), X.end());
	Y.erase(std::unique(Y.begin(), Y.end()), Y.end());

	for (int i = 1; i <= n; i++) {
		int x = std::lower_bound(X.begin(), X.end(), arr[i].second - arr[i].first) - X.begin() + 1;
		int y = std::lower_bound(Y.begin(), Y.end(), arr[i].first + arr[i].second) - Y.begin() + 1;

		plus[x].insert(arr[i]);
		minus[y].insert(arr[i]);
	}

	std::pair<int, int> cur = arr[1], next;

	for (int i = 1; i <= k; i++) {
		int x = std::lower_bound(X.begin(), X.end(), cur.second - cur.first) - X.begin() + 1;
		int y = std::lower_bound(Y.begin(), Y.end(), cur.first + cur.second) - Y.begin() + 1;
		bool flag = false;

		if (str[i] == 'A') {
			auto it = plus[x].lower_bound(cur);
			if (std::next(it) != plus[x].end()) {
				flag = true;
				next = *std::next(it);
			}
		}
		else if(str[i] == 'B'){
			auto it = minus[y].lower_bound(cur);
			if (std::next(it) != minus[y].end()) {
				flag = true;
				next = *std::next(it);
			}
		}
		else if (str[i] == 'C') {
			auto it = minus[y].lower_bound(cur);
			if (it != minus[y].begin()) {
				flag = true;
				next = *std::prev(it);
			}
		}
		else {
			auto it = plus[x].lower_bound(cur);
			if (it != plus[x].begin()) {
				flag = true;
				next = *std::prev(it);
			}
		}

		if (flag) {
			plus[x].erase(cur);
			minus[y].erase(cur);
			cur = next;
		}
	}

	printf("%d %d\n", cur.first, cur.second);
}