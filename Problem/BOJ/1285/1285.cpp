#include <stdio.h>
#include <limits.h>
#include <algorithm>

char arr[30][30];
int r = INT_MAX / 2, n;

void reverse(int idx) {
	for (int i = 1; i <= n; i++) {
		if (arr[idx][i] == 'H')
			arr[idx][i] = 'T';
		else
			arr[idx][i] = 'H';
	}
}

int check(void) {
	int result = 0;
	for (int i = 1; i <= n; i++) {
		int cnt1 = 0, cnt2 = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[j][i] == 'H')
				cnt1++;
			if (arr[j][i] == 'T')
				cnt2++;
		}
		result += std::min(cnt1, cnt2);
	}
	return result;
}

void func(int idx) {
	r = std::min(r, check());

	for (int i = idx; i <= n; i++) {
		reverse(i);
		func(i + 1);
		reverse(i);
	}
}

int main(void) {
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf(" %c", &arr[i][j]);

	func(1);

	printf("%d\n", r);
}