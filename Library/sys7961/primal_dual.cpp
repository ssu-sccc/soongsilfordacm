#include<bits/stdc++.h>


using std::vector;
using std::pair;


struct MCMF {
	struct edge {
		int to;
		int cap;
		int cost;
		int rev;
	};
	vector<vector<edge>> G;
	vector<int> dist;
	vector<int> chk;
	vector<pair<int, int>> from;
	vector<int> pi;
	vector<int> level;
	vector<int> iter;
	int source, sink;
	const int INF = 0x7fffffff / 2;
	MCMF(int n, int source, int sink) :source(source), sink(sink) {
		G.resize(n);
		dist.resize(n);
		chk.resize(n);
		from.resize(n, { -1,-1 });
		level.resize(n);
		iter.resize(n);
	}
	void add_edge(int u, int v, int cap, int cost) {
		edge ori{ v,cap,cost,G[v].size() };
		edge rev{ u,0,-cost,G[u].size() };
		G[u].push_back(ori);
		G[v].push_back(rev);
	}
	void getPotential() {
		std::fill(dist.begin(), dist.end(), INF);
		std::fill(chk.begin(), chk.end(), false);
		std::fill(from.begin(), from.end(), std::make_pair(-1, -1));
		std::fill(level.begin(), level.end(), INF);
		std::queue<int> que;
		que.push(source);
		dist[source] = 0;
		level[source] = 0;
		while (!que.empty()) {
			int idx = que.front();
			que.pop();
			chk[idx] = false;
			for (int i = 0; i < G[idx].size(); i++) {
				auto& e = G[idx][i];
				int to = G[idx][i].to;
				if (e.cap > 0 && dist[to] > dist[idx] + e.cost) {
					dist[to] = dist[idx] + e.cost;
					level[to] = level[idx] + 1;
					from[to] = { idx,i };
					if (!chk[to]) {
						chk[to] = true;
						que.push(to);
					}
				}
			}
		}
		pi = dist;
	}
	bool dijkstra() {

		std::fill(dist.begin(), dist.end(), INF);
		std::fill(chk.begin(), chk.end(), false);
		std::fill(from.begin(), from.end(), std::make_pair(-1, -1));
		std::fill(level.begin(), level.end(), INF);
		int n = dist.size();
		dist[source] = 0;
		using node = pair<int, int>;
		std::priority_queue<node, vector<node>, std::greater<node>> heap;
		heap.emplace(dist[source], source);
		while (!heap.empty()) {
			int idx = heap.top().second;
			heap.pop();
			if (chk[idx])continue;
			chk[idx] = true;

			for (int i = 0; i < G[idx].size(); i++) {
				edge& e = G[idx][i];
				if (e.cap > 0 && dist[e.to] > dist[idx] + e.cost - pi[e.to] + pi[idx]) {
					assert(!chk[e.to]);
					dist[e.to] = dist[idx] + e.cost - pi[e.to] + pi[idx];
					level[e.to] = level[idx]+1;
					from[e.to] = { idx,i };
					heap.emplace(dist[e.to], e.to);
				}
			}


		}
		int idx = sink;
		int cap = INF;
		int cost = dist[sink] + pi[sink] - pi[source];
		if (dist[sink] == INF || cost > 0) {
			return false;
		}
		return true;
	}
	int dfs(int v, int t, int f) {
		if (v == t) return f;
		for (int &i = iter[v]; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if (e.cap > 0 && dist[v] + e.cost - pi[e.to] + pi[v] == 0 && level[v] < level[e.to]) {
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


	pair<int, int> flow() {
		int total_cap = 0;
		int total_cost = 0;

		getPotential();
		while (dijkstra()) {
			std::fill(iter.begin(), iter.end(), 0);
			int f;
			while ((f = dfs(source, sink, INF)) > 0) {
				total_cap += f;
				total_cost += f*(dist[sink] + pi[sink] - pi[source]);
			}
			for (int i = 0; i < dist.size(); i++) {
				if (dist[i] < INF)
					pi[i] += dist[i];
			}
		}
		return{ total_cap,total_cost };
	}
};



int matrix[6][6] = {
	{ 10,8,7,5,0,1 },
	{ 8,6,4,3,0,1 },
	{ 7,4,3,2,0,1 },
	{ 5,3,2,2,0,1 },
	{ 0,0,0,0,0,0 },
	{ 1,1,1,1,0,0 }
};
const int X[4] = { +1,-1,+0,-0 };
const int Y[4] = { +0,-0,+1,-1 };
char str[300][300];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	int ans = 0;
	int source = 0;
	int sink = n*m + 1;
	auto idx = [&](int i, int j) {return i*m + j + 1; };
	auto inner = [&](int i, int j) {return i >= 0 && i < n && j >= 0 && j < m; };
	MCMF mcmf(sink + 1, source, sink);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2 == 0) {
				mcmf.add_edge(source, idx(i, j), 1, 0);
				mcmf.add_edge(idx(i, j), sink, 1, 0);
				for (int p = 0; p < 4; p++) {
					int nx = i + X[p];
					int ny = j + Y[p];
					if (inner(nx, ny)) {
						mcmf.add_edge(idx(i, j), idx(nx, ny), 1, -matrix[str[i][j] - 'A'][str[nx][ny] - 'A']);
					}
				}
			}
			else {
				mcmf.add_edge(idx(i, j), sink, 1, 0);
			}
		}
	}

	printf("%d", -mcmf.flow().second);
}