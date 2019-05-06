#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using std::vector;
struct BipartiteMatching {
	vector<int> L;
	vector<int> R;
	vector<vector<int>> G;
	vector<int> dist;
	BipartiteMatching(int n, int m) {
		L.resize(n, -1);
		R.resize(m, -1);
		G.resize(n);
		dist.resize(n);
	}
	void add_edge(int from, int to) {
		G[from].push_back(to);
	}
	bool bfs() {
		std::queue<int> que;
		for (int i = 0; i < L.size(); i++) {
			if (L[i] == -1) {
				dist[i] = 0;
				que.push(i);
			}
			else {
				dist[i] = -1;
			}
		}
		bool flag = false;
		while (!que.empty()) {
			int idx = que.front();
			que.pop();
			for (int to : G[idx]) {
				if (R[to] == -1)flag = true;
				else if (dist[R[to]] == -1) {
					dist[R[to]] = dist[idx] + 1;
					que.push(R[to]);
				}
			}
		}
		return flag;
	}
	bool dfs(int idx) {
		for (int to : G[idx]) {
			if (R[to] == -1 || (dist[idx]<dist[R[to]] && dfs(R[to]))) {
				R[to] = idx;
				L[idx] = to;
				return true;
			}
		}
		dist[idx] = -1;
		return false;
	}
	int matching() {
		int ret = 0;
		while (bfs()) {
			for (int i = 0; i < L.size(); i++) {
				if (L[i] == -1 && dfs(i)) {
					ret++;
				}
			}
		}
		return ret;
	}

};