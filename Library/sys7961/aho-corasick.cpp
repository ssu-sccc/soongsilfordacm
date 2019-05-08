
using std::string;
const int N = 4;
char alpha[256];
struct aho {
	struct node {
		int vaild = 0;
		int ch;
		int next[N] = { -1,-1,-1,-1 };
		int parent = -1;
		node() {}
		inline int& operator[](int idx) {
			return next[idx];
		}
	};
	vector<node> tree;
	vector<int> idx;
	int cnt = 0;
	aho() {
		tree.push_back(node());
		cnt++;
	}
	void add_string(string str) {
		int p = 0;
		for (char ch : str) {
			if (tree[p][alpha[ch]] == -1) {
				tree.push_back(node());
				tree.back().parent = p;
				tree.back().ch = alpha[ch];
				tree[p][alpha[ch]] = cnt;
				cnt++;
			}
			p = tree[p][alpha[ch]];
		}
		tree[p].vaild++;
	}
	void preprocessing() {
		idx.resize(cnt, -1);
		std::queue<int> que;
		que.push(0);
		while (!que.empty()) {
			int id = que.front();
			que.pop();

			if (id == 0 || tree[id].parent == 0) {
				idx[id] = 0;
			}
			else {
				int p = idx[tree[id].parent];
				int c = tree[id].ch;
				while (p != 0 && tree[p][c] == -1) {
					p = idx[p];
				}
				if (tree[p][c] != -1) {
					p = tree[p][c];
				}
				idx[id] = p;
				tree[id].vaild += tree[p].vaild;
			}
			for (int i = 0; i < N; i++) {
				if (tree[id].next[i] != -1) {
					que.push(tree[id][i]);
				}
			}
		}
	}
	int find_str(string str) {
		int p = 0;
		int ret = 0;
		for (char ch : str) {
			while (p != 0 && tree[p][alpha[ch]] == -1) {
				p = idx[p];
			}
			if (tree[p][alpha[ch]] != -1) {
				p = tree[p][alpha[ch]];
			}
			if (tree[p].vaild) {
				ret += tree[p].vaild;
			}
		}
		return ret;
	}


};