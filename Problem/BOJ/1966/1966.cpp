#include <stdio.h>
#include <queue>

int main(void) {
	int test;
	scanf("%d", &test);

	for (int t = 0; t < test; t++) {
		int n, m, cnt = 0;
		std::queue<std::pair<int, int>> qu;

		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			qu.push({ a, i });
		}

		while (1) {
			bool flag = false;
			auto f = qu.front();
			qu.pop();
			for (int i = 0; i < qu.size(); i++) {
				auto tmp = qu.front();
				qu.pop();
				if (tmp.first > f.first)
					flag = true;
				qu.push(tmp);
			}

			if (!flag) {
				cnt++;
				if (f.second == m)
					break;
			}
			else
				qu.push(f);
		}
		printf("%d\n", cnt);
	}
}