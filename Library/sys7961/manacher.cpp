#include<bits/stdc++.h>
char tmp[100010];
char str[200010];
int A[200010];// palindrome length
int main() {
	scanf("%s", tmp);
	int n = strlen(tmp);
	for (int i = 0; i<n; i++) { // for even palindrome
		str[i * 2] = '#';
		str[i * 2 + 1] = tmp[i];
	}
	str[n * 2] = '#';
	int r = -1, p = -1, ans = 0;
	for (int i = 0; i <= n * 2; i++) {
		if (r < i)A[i] = 0;
		else A[i] = std::min(A[2 * p - i], r - i);
		while (i - A[i] - 1 >= 0 && i + A[i] + 1 <= n * 2 && str[i - A[i] - 1] == str[i + A[i] + 1])A[i]++;
		if (i + A[i] > r) {
			r = i + A[i];
			p = i;
		}
	}
}