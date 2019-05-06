#include<vector>


using std::vector;
struct indexed_tree {
	vector<long long> unit, sum;
	int k = 1;
	indexed_tree(int n) {
		while (k < n)k *= 2;
		unit.resize(k * 3, 0);
		sum.resize(k * 3, 0);
	}
	void update(int left, int right, long long val) {
		int L = left + k, R = right + k;
		int Ls = L, Rs = R;
		long long Lsum = 0, Rsum = 0;
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
	long long query(int left, int right) {
		int L = left + k, R = right + k;
		int Ls = L, Rs = R;
		long long ret = 0;
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


