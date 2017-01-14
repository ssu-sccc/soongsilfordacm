#include <stdio.h>
#include <algorithm>
#include <math.h>

long long arrx[100010], arry[100010];

int main(void) {

	long long n, m, i, result = 0;
	scanf("%lld %lld", &n, &m);

	for(i = 0; i < m; i++)
		scanf("%lld %lld", arrx + i, arry + i);

	std::sort(arrx, arrx + m);
	std::sort(arry, arry + m);

	long long x = arrx[m / 2], y = arry[m / 2];

	for(i = 0; i < m; i++)
		result += abs(x - arrx[i]) + abs(y - arry[i]);

	printf("%lld\n", result);
	return 0;
}