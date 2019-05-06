struct HeavyLightDecomposition {
	vector<int> parent;
	vector<bool> root;
private:
	vector<vector<int>> G;
	vector<int> weight;
	vector<int> top;
	vector<int> idx;
	vector<int> check;
	template <typename T>
	struct indexed_tree {
		vector<T> unit, sum;
		int k = 1;
		indexed_tree(int n) {
			while (k < n)k *= 2;
			unit.resize(k * 3, 0);
			sum.resize(k * 3, 0);
		}
		void update(int left, int right, T val) {
			int L = left + k, R = right + k;
			int Ls = L, Rs = R;
			T Lsum = 0, Rsum = 0;
			int len = 1;
			while (Ls >= 1) {
				sum[Ls] += Lsum;
				sum[Rs] += Rsum;

				if (L <= R) {
					if (L % 2 == 1) {
						unit[L] += val;
						sum[L] += val*len;
						Lsum += val*len;
					}
					if (R % 2 == 0) {
						unit[R] += val;
						sum[R] += val*len;
						Rsum += val*len;
					}
				}
				L = (L + 1) / 2, R = (R - 1) / 2;
				Ls /= 2; Rs /= 2;
				len *= 2;
			}
		}
		T query(int left, int right) {
			int L = left + k, R = right + k;
			int Ls = L, Rs = R;
			T ret = 0;
			int Llen = 0, Rlen = 0;
			int len = 1;
			while (Ls >= 1) {
				ret += unit[Ls] * Llen + unit[Rs] * Rlen;

				if (L <= R) {
					if (L % 2 == 1) {
						ret += sum[L];
						Llen += len;
					}
					if (R % 2 == 0) {
						ret += sum[R];
						Rlen += len;
					}
				}
				L = (L + 1) / 2, R = (R - 1) / 2;
				Ls /= 2; Rs /= 2;
				len *= 2;
			}
			return ret;
		}
	};
	indexed_tree<int> tree;
	//LCA
	vector<vector<int>> ancestor;
	vector<int> height;
	int lca_log = 20;
	void processing(int node, int Parent) {
		weight[node] = 1;
		ancestor[0][node] = parent[node] = Parent;
		for (int p : G[node]) {
			if (p == Parent) continue;
			height[p] = height[node] + 1;
			processing(p, node);
			weight[node] += weight[p];
		}
	}
	int getLCA(int a, int b) {
		if (height[a] < height[b]) std::swap(a, b);
		int dx = height[a] - height[b];
		for (int i = 0; i < lca_log; i++)
			if ((dx >> i) & 1)
				a = ancestor[i][a];
		if (a == b) return a;
		for (int i = lca_log; i >= 0; i--)
			if (ancestor[i][a] != ancestor[i][b])
				a = ancestor[i][a], b = ancestor[i][b];
		return ancestor[0][a];
	}
	void initLCA(int root) {
		ancestor.resize(lca_log + 5, vector<int>(G.size()));
		height.resize(G.size(), 0);
		processing(root, root);
		for (int i = 1; (1 << i) < G.size(); i++)
			for (int j = 1; j < G.size(); j++)
				ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
	}

	int cnt = 1;
	void chaining(int node, int Top) {
		idx[node] = cnt;
		top[node] = Top;
		check[node] = true;
		cnt++;
		std::priority_queue<pair<int, int>> heap;
		for (int next : G[node]) {
			if (next != parent[node]) {
				heap.push({ weight[next],next });
			}
		}
		if (heap.empty()) { // is leaf
			return;
		}

		chaining(heap.top().second, Top);
		heap.pop();
		while (!heap.empty()) {
			chaining(heap.top().second, heap.top().second);
			heap.pop();
		}
	}
public:

	bool edge;
	HeavyLightDecomposition(int n, bool edge) :edge(edge), tree(n + 1) {
		G.resize(n + 1);
		weight.resize(n + 1);
		top.resize(n + 1);
		idx.resize(n + 1);
		parent.resize(n + 1, -1);
		check.resize(n + 1, false);
		root.resize(n + 1, false);
	}
	void add_edge(int a, int b) {
		G[a].push_back(b);
		G[b].push_back(a);
	}
	void init() {
		for (int i = 1; i < check.size(); i++) {
			if (!check[i]) {
				root[i] = true;
				initLCA(i);
				chaining(i, i);
			}
		}
	}
	void update(int A, int B, int Cost) {
		int lca = getLCA(A, B);
		while (true) {
			if (top[A] == top[lca]) {
				tree.update(idx[lca], idx[A], Cost);
				break;
			}
			else {
				tree.update(idx[top[A]], idx[A], Cost);
				A = parent[top[A]];
			}
		}
		while (true) {
			if (top[B] == top[lca]) {
				tree.update(idx[lca], idx[B], Cost);
				break;
			}
			else {
				tree.update(idx[top[B]], idx[B], Cost);
				B = parent[top[B]];
			}
		}
		if (edge) {
			tree.update(idx[lca], idx[lca], -Cost * 2);
		}
		else {
			tree.update(idx[lca], idx[lca], -Cost);
		}
	}
	int query(int A, int B) {
		int lca = getLCA(A, B);
		int ret = 0;
		while (true) {
			if (top[A] == top[lca]) {
				ret += tree.query(idx[lca], idx[A]);
				break;
			}
			else {
				ret += tree.query(idx[top[A]], idx[A]);
				A = parent[top[A]];
			}
		}
		while (true) {
			if (top[B] == top[lca]) {
				ret += tree.query(idx[lca], idx[B]);
				break;
			}
			else {
				ret += tree.query(idx[top[B]], idx[B]);
				B = parent[top[B]];
			}
		}
		if (edge) {
			ret -= tree.query(idx[lca], idx[lca]) * 2;
		}
		else {
			ret -= tree.query(idx[lca], idx[lca]);
		}
		return ret;
	}
};