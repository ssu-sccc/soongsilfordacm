#include<bits/stdc++.h>
using std::vector;
using std::queue;
const int INF = 0x7fffffff / 2;
struct Dinic {

	struct edge {
		int to, cap, rev,ccap;
		edge() {}
		edge(int a, int b, int c) :to(a), cap(b), rev(c) ,ccap(cap){}
	};
	vector<vector<edge>> G;
	vector<int> level;
	vector<int> iter;
	int source;
	int sink;
	int newsource;
	int newsink;
	int lowsum = 0;
	Dinic(int n, int source, int sink) :source(source), sink(sink) {
		G.resize(n+2);
		level.resize(n+2);
		iter.resize(n+2);
		newsource = n;
		newsink = n + 1;
		add_edge(sink, source, INF);
	}


	void add_edge(int from, int to, int cap)
	{
		edge e(to, cap, G[to].size());
		edge re(from, 0, G[from].size());
		G[from].push_back(e);
		G[to].push_back(re);
	}
	void add_edge(int from, int to, int mcap, int Mcap) {
		add_edge(from, to, Mcap - mcap);
		add_edge(from, newsink, mcap);
		add_edge(newsource, to, mcap);
		lowsum += mcap;
	}
	void bfs(int s) {
		std::fill(level.begin(), level.end(), -1);
		queue<int> que;
		level[s] = 0;
		que.push(s);
		while (!que.empty()) {
			int v = que.front();
			que.pop();
			for (int i = 0; i < G[v].size(); i++) {
				edge & e = G[v][i];
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					que.push(e.to);
				}
			}
		}
	}
	int dfs(int v, int t, int f) {
		if (v == t) return f;
		for (int &i = iter[v]; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
				int d = dfs(e.to, t, std::min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	std::pair<int,bool> flow() {
		int flow = 0;
		
		while (true) {
			bfs(newsource);
			if (level[newsink] < 0) break;
			std::fill(iter.begin(), iter.end(), 0);
			int f;
			while ((f = dfs(newsource, newsink, INF)) > 0) {
				flow += f;
			}
		}
		
		return{ flow,true };
	}
};

int matrix[300][300][2];
int col[300][2];
int row[300][2];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d.%d", &matrix[i][j][0], &matrix[i][j][1]);
		}
		scanf("%d.%d", &row[i][0], &row[i][1]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d.%d", &col[i][0], &col[i][1]);
	}
	int source = 0;
	int sink = n + m + 1;
	auto R = [&](int i) {return i + 1; };
	auto C = [&](int i) {return i + n + 1; };
	Dinic D(sink + 1, source, sink);
	for (int i = 0; i < n; i++) {
		D.add_edge(source, R(i), row[i][0] , row[i][0] + (row[i][1] != 0));
		row[i][0] = 0;
	}
	for (int i = 0; i < m; i++) {
		D.add_edge(C(i),sink, col[i][0] , col[i][0] + (col[i][1] != 0));
		col[i][0] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			D.add_edge(R(i), C(j), matrix[i][j][0], matrix[i][j][0] + (matrix[i][j][1] != 0));
		}
	}
	auto ret=D.flow();
//	printf("%d\n", ret.first);
	auto& G = D.G;
	for (int i = 0; i < n; i++) {
		for (auto e : G[R(i)]) {
			if (C(0) <= e.to && e.to <= C(m - 1)) {
				matrix[i][e.to-n-1][0] += G[e.to][e.rev].cap;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			row[i][0] += matrix[i][j][0];
			col[j][0] += matrix[i][j][0];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", matrix[i][j][0]);
		}
		printf("%d\n", row[i][0]);
	}
	for (int i = 0; i < m; i++) {
		printf("%d ", col[i][0]);
	}

	

}