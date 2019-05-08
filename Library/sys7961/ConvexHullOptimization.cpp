#include<bits/stdc++.h>
using std::vector;
using std::pair;
using lint = long long int;
using pii = std::pair<int, int>;
using pll = std::pair<lint, lint>;
struct line {
	lint A, B;
};
lint dy[50010];
bool cmp(line& A, line& B, line& C) {
	lint u1 = (B.B - A.B);
	lint d1 = (A.A - B.A);

	lint u2 = (C.B - B.B);
	lint d2 = (B.A - C.A);

	return u1*d2 > u2*d1;
}
lint getVal(line& p, lint x) {
	return p.A*x + p.B;
}
int main(void) {
	memset(dy, 0x3f, sizeof(dy));
	dy[0] = 0;
	vector<pll> ract;
	/*  some of data increase gradient at ract  */
	vector<line> stack;
	vector<double> points;
	int n = ract.size() - 1;
	int idx2 = 0;
	for (int i = 1; i <= n; i++) {
		line p = { ract[i].second,dy[i - 1] };
		while (stack.size() >= 2 && cmp(*(stack.end() - 2), *(stack.end() - 1), p)) {
			stack.pop_back();
			if (!points.empty())points.pop_back();
		}
		if (!stack.empty()) {
			points.push_back((double)(p.B - stack.back().B) / (stack.back().A - p.A));
		}
		stack.push_back(p);
/*   	idx2 = std::min<int>(idx2, stack.size() - 1);*/
		lint w = ract[i].first;

		int idx = std::lower_bound(points.begin(), points.end(), (double)w) - points.begin();
		dy[i] = std::min(dy[i], getVal(stack[idx], w));
		/* while (idx != stack.size() - 1 && getVal(stack[idx], w) > getVal(stack[idx + 1], w)) {
		idx++;
		}
		dy[i] = std::min(dy[i], getVal(stack[idx], w));*/
	}
	printf("%lld", dy[n]);
	return 0;

}
