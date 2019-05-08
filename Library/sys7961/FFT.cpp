#include<bits/stdc++.h>

using std::vector;
using std::pair;
using lint = long long int;
using pii = std::pair<int, int>;

#include<complex>
using base = std::complex<double>;

void fft(vector<base>& a, bool inv) {
	int n = a.size();
	for (int i = 1, j = 0; i < n; i++) {
		int bit = (n >> 1);
		while (j >= bit) {
			j ^= bit; bit >>= 1;
		}
		j |= bit;
		if (i < j)std::swap(a[i], a[j]);
	}

	double ang = 2.0*acos(-1) / n * (inv ? -1.0 : 1.0);
	vector<base> W(n);
	for (int i = 0; i < n; i++)W[i] = base(cos(ang*i), sin(ang*i));

	for (int k = 2; k <= n; k <<= 1) {
		int step = n / k;
		for (int i = 0; i < n; i += k) {
			for (int j = 0; j < k / 2; j++) {
				base u = a[i + j], v = a[i + j + k / 2];
				a[i + j] = u + W[step*j] * v;
				a[i + j + k / 2] = u - W[step*j] * v;
			}
		}
	}
	if (inv)for (int i = 0; i < n; i++)a[i] /= n;
}

vector<lint> multiply(vector<lint>& A, vector<lint>& B, lint mod) {
	int n = 1;
	while (n < std::max(A.size(), B.size()))n <<= 1;
	n <<= 1;
	vector<base> b1(n, 0), b2(n, 0), s1(n, 0), s2(n, 0);
	for (int i = 0; i < A.size(); i++) {
		b1[i] = A[i] >> 15;
		s1[i] = A[i] & ((1 << 15) - 1);
	}
	for (int i = 0; i < B.size(); i++) {
		b2[i] = B[i] >> 15;
		s2[i] = B[i] & ((1 << 15) - 1);
	}
	fft(b1, false);
	fft(s1, false);
	fft(b2, false);
	fft(s2, false);
	vector<base> b1b2(n, 0), b1s2(n, 0), s1b2(n, 0), s1s2(n, 0);
	for (int i = 0; i < n; i++) {
		b1b2[i] = b1[i] * b2[i];
		b1s2[i] = b1[i] * s2[i];
		s1b2[i] = s1[i] * b2[i];
		s1s2[i] = s1[i] * s2[i];
	}
	fft(b1b2, true);
	fft(b1s2, true);
	fft(s1b2, true);
	fft(s1s2, true);
	vector<lint> ret(n);
	for (int i = 0; i < n; i++) {
		lint ac = b1b2[i].real() + 0.5;
		lint ad = b1s2[i].real() + 0.5;
		lint bc = s1b2[i].real() + 0.5;
		lint bd = s1s2[i].real() + 0.5;
		ac %= mod; ad %= mod; bc %= mod; bd %= mod;
		ret[i] = (ac << 30) + ((ad + bc) << 15) + bd;
		ret[i] %= mod;
		ret[i] += mod;
		ret[i] %= mod;
	}
	return ret;

}


