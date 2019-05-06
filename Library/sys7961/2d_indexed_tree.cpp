#include<bits/stdc++.h>

using std::vector;
using data_ty = int;
struct indexed_tree {
	vector<data_ty> unit, sum;
	int k = 1;
	indexed_tree(int n) {
		while (k < n)k *= 2;
		unit.resize(k * 2+1, 0);
		sum.resize(k * 2+1, 0);
	}
	void update(int left, int right, data_ty val) {
		int L = left + k, R = right + k;
		int Ls = L, Rs = R;
		data_ty Lsum = 0, Rsum = 0;
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
	data_ty query(int left, int right) {
		int L = left + k, R = right + k;
		int Ls = L, Rs = R;
		data_ty ret = 0;
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

struct indexed_tree_2d {
	vector<indexed_tree> unit, sum;
	int k = 1;
	indexed_tree_2d(int n) {
		while (k < n)k *= 2;
		unit.resize(k * 2+1, indexed_tree(n));
		sum.resize(k * 2+1, indexed_tree(n));
	}
	void update(int xl, int xr, int yl, int yr, data_ty val) {
		int L = xl + k, R = xr + k;
		int Ls = L, Rs = R;
		data_ty Lsum = 0, Rsum = 0;
		int len = 1;
		while (Ls >= 1) {
			sum[Ls].update(yl, yr, Lsum);
			sum[Rs].update(yl, yr, Rsum);

			if (L <= R) {
				if (L % 2 == 1) {
					unit[L].update(yl, yr, val);
					sum[L].update(yl, yr, val*len);
					Lsum += val*len;
				}
				if (R % 2 == 0) {
					unit[R].update(yl, yr, val);
					sum[R].update(yl, yr, val*len);
					Rsum += val*len;
				}
			}
			L = (L + 1) / 2, R = (R - 1) / 2;
			Ls /= 2; Rs /= 2;
			len *= 2;
		}
	}

	data_ty query(int xl, int xr, int yl, int yr) {
		int L = xl + k, R = xr + k;
		int Ls = L, Rs = R;
		data_ty ret = 0;
		int Llen = 0, Rlen = 0;
		int len = 1;
		while (Ls >= 1) {
			ret += unit[Ls].query(yl,yr)*Llen + unit[Rs].query(yl,yr)*Rlen;

			if (L <= R) {
				if (L % 2 == 1) {
					ret += sum[L].query(yl, yr);
					Llen += len;
				}
				if (R % 2 == 0) {
					ret += sum[R].query(yl, yr);
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
int arr[1025][1025];


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	indexed_tree_2d tree(n+1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			scanf("%d", &a);
			arr[i][j] = a;
			tree.update(i, i, j, j, a);
		}
	}
	while (m--) {
		int w;
		scanf("%d", &w);
		if (w == 0) {
			int x1, y1,x2,y2, c;
			scanf("%d%d%d%d%d", &x1, &y1,&x2,&y2, &c);
			tree.update(x1, x2, y1, y2, c);
		}
		else {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			printf("%d\n", tree.query(x1, x2, y1, y2));
		}
	}
}