#include<stdio.h>
#include<vector>
const int N=10000;
long long phi[N+1] = { 1,1 };
long long up[N+1];
long long down[N+1];
bool chk[N+1] = { 1,1 };
int main() {
	for (int i = 0; i <= N; i++) {
		up[i] = i;
		down[i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		if (!chk[i]) {
			up[i] *= i - 1;
			down[i] *= i;
			for (int j = i * 2; j <= N; j += i) {
				chk[j] = true;
				up[j] *= i - 1;
				down[j] *= i;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		phi[i] = up[i] / down[i];
	}
	
}