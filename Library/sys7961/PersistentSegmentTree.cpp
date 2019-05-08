struct PersistentSegmentTree {
	struct node {
		int sum = 0;
		int L = -1, R = -1;
	};
	vector<node> tree;
	vector<int> root;
	int n;
	PersistentSegmentTree(int n) :n(n) {
		root.push_back(init(0, n - 1));
	}
	int init(int s, int e) {
		node p;
		if (s != e) {
			int m = (s + e) / 2;
			p.L = init(s, m);
			p.R = init(m + 1, e);
		}
		tree.push_back(p);
		return tree.size() - 1;
	}
	int add(int idx, int par, int a) {
		root.push_back(add(tree[root[par]], 0, n - 1, idx, a));
		return root.size() - 1;
	}
	int add(node p, int s, int e, int idx, int a) {
		int m = (s + e) / 2;
		node q = p;
		q.sum = a;
		if (s != e) {
			if (s <= idx && idx <= m) {
				q.L = add(tree[p.L], s, m, idx, a);
			}
			else {
				q.R = add(tree[p.R], m + 1, e, idx, a);
			}
			q.sum = tree[q.L].sum + tree[q.R].sum;
		}
		tree.push_back(q);
		return tree.size() - 1;
	}
	int getRange(int s, int e, int l, int r, int aidx, int bidx) {
		int m = (s + e) / 2;
		int ret = 0;
		if (r<s || e<l) {
			return 0;
		}
		if (l <= s && e <= r) {
			ret += tree[bidx].sum - tree[aidx].sum;
			return ret;
		}
		ret = getRange(s, m, l, r, tree[aidx].L, tree[bidx].L) + getRange(m + 1, e, l, r, tree[aidx].R, tree[bidx].R);
		return ret;

	}
	int getRange(int l, int r, int a, int b) {
		if (a > b || l > r)return 0;
		return getRange(0, n - 1, l, r, root[a], root[b]);
	}
};