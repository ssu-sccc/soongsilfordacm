#include <stdio.h>
#include <algorithm>

int arr[10010];

void func(int s, int e) {
	for (int i = 0; i < (e - s + 1) / 2; i++)
		std::swap(arr[s + i], arr[e - i]);
}

int main(void) {
	int n, first = 0, finish;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", arr + i);
		if (first == 0 && arr[i] != i)
			first = i;
	}

	if (first == 0) {
		printf("1 1\n1 1\n");
		return 0;
	}

	for (int i = first; i <= n; i++) {
		int e2 = arr[i];
		func(std::min(i, e2), std::max(i, e2));
		finish = 0;
		for (int j = first; j <= n; j++) {
			if (arr[j] != j) {
				finish = j;
				break;
			}
		}

		if (finish == 0) {
			printf("%d %d\n1 1\n", std::min(i, e2), std::max(i, e2));
			break;
		}

		int e = arr[finish];
		func(std::min(finish, e), std::max(e, finish));

		bool flag = false;
		for (int j = first; j <= n; j++) {
			if (arr[j] != j) {
				flag = true;
				break;
			}
		}

		if (!flag) {
			printf("%d %d\n%d %d\n", std::min(i, e2), std::max(i, e2), std::min(finish, e), std::max(e, finish));
			break;
		}
	
		func(std::min(finish, e), std::max(e, finish));
		func(std::min(i, e2), std::max(i, e2));
	}
}