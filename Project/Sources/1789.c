#include <stdio.h>
#include <math.h>
int main()
{
	long long s,t=0,n=0;
	scanf("%lld",&s);
	while(n<=s)	n+=++t;
	printf("%lld\n",t-1);
}
