/*
파일합치기 2
*/
#include<bits/stdc++.h>
using std::vector;
using std::pair;
using lint = long long int;
using pii = std::pair<int, int>;
lint C[5010];
int opt[5010][5010];
lint dy[5010][5010];
lint sum[5010];
int main(void) {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &C[i]);
			sum[i] = sum[i - 1] + C[i];
			for (int j = 1; j <= n; j++) {
				opt[i][j] = -1;
				dy[i][j] = 0x7fffffffffffffffLL / 2;
			}
			opt[i][i] = i;
			dy[i][i] = 0;
		}
		for (int d = 1; d < n; d++) {
			for (int i = 1; i + d <= n; i++) {
				int j = i + d;
				for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; k++) {
					if (dy[i][j] > dy[i][k] + dy[k + 1][j] + sum[j] - sum[i - 1]) {
						dy[i][j] = dy[i][k] + dy[k + 1][j] + sum[j] - sum[i - 1];
						opt[i][j] = k;
					}
				}
			}
		}
		printf("%lld\n", dy[1][n]);
	}
	return 0;
}
