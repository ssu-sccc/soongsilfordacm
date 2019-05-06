#include<vector>
#include<algorithm>
#include<stdio.h>

using std::vector;
using std::pair;

using data_Ty = long long;
using data_Node = pair<int, data_Ty>;
struct indexed_tree {
	vector<data_Node> tree;
	vector<data_Node> lazy;
	int k = 1;
	data_Node init = { -1,0 };
	int _Time = 0;
	bool revCmp(data_Node& a, data_Node& b)const {
		return std::make_pair(a.second, a.first) < std::make_pair(b.second, b.first);
	}
	data_Node revMax(data_Node a, data_Node b)const {
		if (revCmp(a, b)) {
			return b;
		}
		return a;
	}

	indexed_tree() {}
	indexed_tree(int n) {
		while (k < n)k *= 2;
		tree.resize(k * 3, init);
		lazy.resize(k * 3, init);
	}

	data_Ty lazyUp(int idx, int len, data_Ty a) {
		data_Node ret = init;
		int p = len;
		int temp = idx / 2;
		ret = std::max(tree[idx], lazy[idx]);
		while (temp) {
			tree[temp] = revMax(std::max(tree[temp * 2], lazy[temp * 2]), std::max(tree[temp * 2 + 1], lazy[temp * 2 + 1]));
			ret = std::max(ret, lazy[temp]);
			p *= 2;
			temp /= 2;
		}
		return ret.second;
	}


	data_Ty query(int left, int right, data_Ty a) {
		data_Ty ret = init.second;
		left += k;
		right += k;
		int len = 1;
		while (left <= right) {
			if (left % 2 == 1) {
				if (a != -1)
					lazy[left] = { _Time,a };
				ret = std::max(ret, lazyUp(left, len, a));
			}
			if (right % 2 == 0) {
				if (a != -1)
					lazy[right] = { _Time,a };
				ret = std::max(ret, lazyUp(right, len, a));
			}
			left = (left + 1) / 2;
			right = (right - 1) / 2;
			len *= 2;
		}
		_Time++;
		return ret;
	}
	void update(int left, int right, data_Ty a) {
		query(left, right, a);
	}
	data_Ty getRange(int left, int right) {
		return query(left, right, -1);
	}
};
