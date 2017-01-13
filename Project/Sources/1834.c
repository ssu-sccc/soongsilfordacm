#include <stdio.h>
int main()
{
	long long n,s=0;
	scanf("%lld",&n);
	for(long long i=1;i<n;i++)
		s+=i*n+i;
	printf("%lld\n",s);
}
