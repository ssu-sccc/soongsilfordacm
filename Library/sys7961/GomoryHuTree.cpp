
const int N = 3010;
vector<pii> G[N];
int n;//vertex
int m;
int flow[N][N];
int p[N];
void gomoriHu() {
	for (int i = 0; i < n; i++)p[i] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			flow[i][j] = INF;
		}
	}
	for (int i = 1; i < n; i++) {
		Dinic D(n + 1, i, p[i]);
		for (int i = 0; i < n; i++) {
			for (pii e : G[i]) {
				D.add_edge(i, e.first, e.second);
			}
		}
		int f = D.flow();
		for (int j = i + 1; j <= n - 1; j++) {
			if (D.level[j] >= 0 && p[j] == p[i])p[j] = i;
		}
		flow[i][p[i]] = flow[p[i]][i] = f;
		for (int j = 0; j < i; j++) {
			flow[j][i] = flow[i][j] = std::min(flow[j][p[i]], f);
		}
	}
	for (int i = 0; i < n; i++) {
		flow[i][i] = 0;
	}
}