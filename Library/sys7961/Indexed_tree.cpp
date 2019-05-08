#include<vector>
#include<stdio.h>


using std::vector;
struct indexed_tree {
	vector<long long> unit,sum;
	int k = 1;
	indexed_tree(int n) {
		while (k < n)k *= 2;
		unit.resize(k * 3, 0);
		sum.resize(k * 3, 0);
	}
	void update(int left, int right,long long val) {
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








int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	indexed_tree tree(n+1);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		tree.update(i, i, a);
	}
	for (int i = 0; i < m + k; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b, c, d;
			scanf("%d%d%d", &b, &c, &d);
			if (b > c)std::swap(b, c);
			tree.update(b, c, d);
		}
		else {
			int b, c;
			scanf("%d%d", &b, &c);
			if (b > c)std::swap(b, c);
			printf("%lld\n", tree.query(b, c));
		}
	}
}