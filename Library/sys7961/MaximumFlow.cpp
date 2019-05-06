#include<bits/stdc++.h>
using std::vector;
using std::queue;
const int INF = 0x7fffffff / 2;
struct Dinic {
	struct edge {
		int to, cap, rev;
		edge() {}
		edge(int a, int b, int c) :to(a), cap(b), rev(c) {}
	};
	vector<vector<edge>> G;
	vector<int> level;
	vector<int> iter;
	int source;
	int sink;
	Dinic(int n, int source, int sink) :source(source), sink(sink) {
		G.resize(n);
		level.resize(n);
		iter.resize(n);
	}
	void add_edge(int from, int to, int cap)
	{
		edge e(to, cap, G[to].size());
		edge re(from, 0, G[from].size());
		G[from].push_back(e);
		G[to].push_back(re);
	}
	bool bfs(int s) {
		std::fill(level.begin(), level.end(), -1);
		std::fill(iter.begin(), iter.end(), 0);
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
		return level[sink] >= 0;
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
	int flow() {
		int flow = 0;
		while (bfs(source)) {
			int f;
			while ((f = dfs(source, sink, INF)) > 0) {
				flow += f;
			}
		}
		return flow;
	}
};