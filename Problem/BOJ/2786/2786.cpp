#include <stdio.h>
#include <algorithm>

struct info {
	long long d1, d2;
};

info arr[500010];
long long d_small[500010], gap_small[500010], sum[500010];
bool compare(info a, info b){
	if(a.d2 < b.d2) return true;
	else return false;
}
int main(void)
{


	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%lld %lld", &arr[i].d1, &arr[i].d2);

	std::sort(arr, arr + n, compare); 

	d_small[n - 1] = arr[n - 1].d1;

	for(int i = n - 2; i >= 0; i--)
		d_small[i] = std::min(d_small[i + 1], arr[i].d1); 
	
	gap_small[0] = arr[0].d1 - arr[0].d2;
	printf("%lld\n", d_small[0]);
	sum[0] = arr[0].d2;
	d_small[n] = 1000000010;

	for(int i = 1; i < n; i++)
	{
		sum[i] += sum[i - 1] + arr[i].d2;
		gap_small[i] = std::min(gap_small[i - 1], arr[i].d1 - arr[i].d2);
		printf("%lld\n", std::min(sum[i] + gap_small[i], sum[i] - arr[i].d2 + d_small[i + 1]));
	}
	
	return 0;
}