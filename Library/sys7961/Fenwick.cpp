#include<vector>



using std::vector;
struct Fenwick {
private:
	vector<long long> main,sub;
	int n;
	void update(int idx, long long val,vector<long long>& tree) {
		while (idx <= n) {
			tree[idx] += val;
			idx += (idx&-idx);
		}
	}
	long long query(int idx,vector<long long>& tree) {
		long long ret = 0;
		while (idx) {
			ret += tree[idx];
			idx -= (idx&-idx);
		}
		return ret;
	}

	void update_main(int idx, long long val) {
		update(idx, val, main);
	}
	void update_sub(int idx, long long val) {
		update(idx, val, sub);
	}
	long long query_main(int idx) {
		return query(idx, main);
	}
	long long query_sub(int idx) {
		return query(idx, sub);
	}
	void startZero(int& left, int& right) {
	//	left++; right++;
	}
public:
	Fenwick(int n) :n(n) {
		main.resize(n + 1, 0);
		sub.resize(n + 1, 0);
	}
	void rangeUpdate(int left, int right, long long val) {
		startZero(left, right);
		right++;
		update_main(left, val); update_main(right, -val);
		update_sub(left, -val*(left-1)); update_sub(right, val*(right-1));
	}
	long long rangeQuery(int left, int right) {
		startZero(left ,right);
		left--;
		long long ret = 0;
		ret += query_main(right)*right + query_sub(right);
		ret -= query_main(left)*left+query_sub(left);
		return ret;
	}
};
