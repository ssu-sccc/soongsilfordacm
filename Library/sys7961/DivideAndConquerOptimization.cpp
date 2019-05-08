/**************************
acmicpc.net/problem/13261
***************************/
#include<bits/stdc++.h>
using std::vector;
using std::pair;
using lint = long long int;
using pii = std::pair<int, int>;


lint dy[810][8010];
int opt[810][8010];
lint C[8010];
lint sum[8010];
lint cost(int L, int R) {
	return (sum[R] - sum[L - 1])*(R - L + 1);
}
void go(int L, int R, int s, int e, int k) {
	if (L > R)return;

	int m = (L + R) / 2;
	for (int i = s; i <= e; i++) { // for example, for(int i=std::max(k,s);i<=std::min(m,e);i++)
		if (dy[k][m] > dy[k - 1][i - 1] + cost(i, m)) {
			dy[k][m] = dy[k - 1][i - 1] + cost(i, m);
			opt[k][m] = i;
		}
	}
	go(L, m - 1, s, opt[k][m], k);
	go(m + 1, R, opt[k][m], e, k);
}

int main(void) {
	memset(dy, 0x3f, sizeof(dy));
	int l, g;
	scanf("%d%d", &l, &g);
	for (int i = 1; i <= l; i++) {
		scanf("%lld", &C[i]);
		sum[i] = sum[i - 1] + C[i];
		dy[1][i] = cost(1, i);
	}
	dy[1][0] = 0;

	for (int i = 2; i <= g; i++) {
		go(1, l, 1, l, i);
	}
	printf("%lld", dy[g][l]);

	return 0;
}
