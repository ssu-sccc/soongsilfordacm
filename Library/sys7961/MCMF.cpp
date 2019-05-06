#include<stdio.h>
#include<vector>
#include<queue>
using std::vector;
using std::pair;
struct MCMF {
	struct Edge {
		int to;
		int cap;
		int cost;
		int rev;
	};
	vector<vector<Edge>> G;
	vector<int> dist;
	vector<int> chk;
	vector<pair<int, int>> from;
	int source, sink;
	const int INF = 0x7fffffff / 2;
	MCMF(int n, int source, int sink) :source(source), sink(sink) {
		G.resize(n);
		dist.resize(n);
		chk.resize(n);
		from.resize(n, { -1,-1 });
	}
	void add_edge(int u, int v, int cap, int cost) {
		Edge ori{ v,cap,cost,G[v].size() };
		Edge rev{ u,0,-cost,G[u].size() };
		G[u].push_back(ori);
		G[v].push_back(rev);
	}
	bool spfa(int& total_cap, int& total_cost) {
		std::fill(dist.begin(), dist.end(), INF);
		std::fill(chk.begin(), chk.end(), false);
		std::fill(from.begin(), from.end(), std::make_pair(-1, -1));
		std::queue<int> que;
		que.push(source);
		dist[source] = 0;
		while (!que.empty()) {
			int idx = que.front();
			que.pop();
			chk[idx] = false;
			for (int i = 0; i < G[idx].size(); i++) {
				auto& e = G[idx][i];
				int to = G[idx][i].to;
				if (e.cap > 0 && dist[to] > dist[idx] + e.cost) {
					dist[to] = dist[idx] + e.cost;
					from[to] = { idx,i };
					if (!chk[to]) {
						chk[to] = true;
						que.push(to);
					}
				}
			}
		}
		if (dist[sink] == INF) {
			return false;
		}
		int idx = sink;
		int c = INF;
		while (idx != source) {
			c = std::min(c, G[from[idx].first][from[idx].second].cap);
			idx = from[idx].first;
		}
		idx = sink;
		while (idx != source) {
			int rev = G[from[idx].first][from[idx].second].rev;
			G[from[idx].first][from[idx].second].cap -= c;
			G[idx][rev].cap += c;
			idx = from[idx].first;
		}
		total_cap += c;
		total_cost += dist[sink] * c;
		return true;

	}
	pair<int, int> flow() {
		int total_cap = 0;
		int total_cost = 0;
		while (spfa(total_cap, total_cost));
		return{ total_cap,total_cost };
	}
};