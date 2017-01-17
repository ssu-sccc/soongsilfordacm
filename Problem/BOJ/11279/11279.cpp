#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>

std::priority_queue<int, std::vector<int>, std::less<int>> qu;

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);

		if (a == 0) {
			if (qu.empty())
				printf("0\n");
			else {
				printf("%d\n", qu.top());
				qu.pop();
			}
		}
		else
			qu.push(a);
	}
}