#include<bits/stdc++.h>



using std::vector;
using std::string;
struct suffixArray {
	string str;
	vector<int> group;
	vector<int> sa;
	vector<int> tmp;
	vector<int> cnt;
	vector<int> cnt2;
	int len;
	suffixArray(string str) :str(str) {
		len = str.size();
		group.resize(len * 2+10, -1);
		sa.resize(len,0);
		tmp.resize(len,0);
		cnt.resize(len, 0);
		cnt2.resize(len, 0);
	}
	vector<int> getSA() {
		int len = str.size();
		int m = 255;
		for (int i = 0; i < len; i++) {
			sa[i] = i;
			group[i] = str[i];
		}

		group[len] = -1;
		for (int k = 1; k < len; k *= 2) {
			for (int i = 0; i <= m; i++) { cnt[i] = 0; cnt2[i] = 0; }
			for (int i = 0; i < len; i++) { cnt[group[sa[i] + k] + 1]++; }
			for (int i = 1; i <= m; i++) { cnt[i] += cnt[i - 1]; }
			for (int i = len - 1; i >= 0; i--) { tmp[--cnt[group[sa[i] + k] + 1]] = sa[i]; }
			for (int i = 0; i < len; i++) { cnt2[group[tmp[i]]]++; }
			for (int i = 1; i <= m; i++) { cnt2[i] += cnt2[i - 1]; }
			for (int i = len - 1; i >= 0; i--) { sa[--cnt2[group[tmp[i]]]] = tmp[i]; }
			tmp[sa[0]] = 0;
			tmp[len] = -1;
			for (int j = 1; j < len; j++) {
				if (group[sa[j - 1]] == group[sa[j]] && group[sa[j - 1] + k] == group[sa[j] + k]) {
					tmp[sa[j]] = tmp[sa[j - 1]];
				}
				else {
					tmp[sa[j]] = tmp[sa[j - 1]] + 1;
				}
			}
			int q = 0;
			for (int j = 0; j < len; j++) {
				group[j] = tmp[j];
				q = std::max(q, tmp[j]);
			}
			m = q + 1;
		}
		return sa;
	}
	vector<int> getLCP() {
		vector<int> pi(len, -1);
		vector<int> plcp(len);
		vector<int> lcp(len, -1);
		for (int i = 1; i < len; i++) { pi[sa[i]] = sa[i - 1]; }
		int k = 0;
		for (int i = 0; i < len; i++) {
			if (pi[i] == -1) {
				plcp[i] = 0;
				continue;
			}
			while (str[i + k] == str[pi[i] + k])k++;
			plcp[i] = k;
			k = std::max(k - 1, 0);
		}
		for (int i = 0; i < len; i++) {lcp[i] = plcp[sa[i]]; }
		return lcp;
	}
};
