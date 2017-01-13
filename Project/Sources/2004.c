#include <stdio.h>
int main()
{
	long long n,m,five=0,mm,two=0,i;
	scanf("%lld%lld",&n,&m);
	for(i=5;n/i>=1;i*=5)
		five+=n/i;
	for(i=5;m/i>=1;i*=5)
		five-=m/i;
	for(i=5;(n-m)/i>=1;i*=5)
		five-=(n-m)/i;

	for(i=2;n/i>=1;i*=2)
		two+=n/i;
	for(i=2;m/i>=1;i*=2)
		two-=m/i;
	for(i=2;(n-m)/i>=1;i*=2)
		two-=(n-m)/i;
	printf("%lld\n",(five>two?two:five)<0?0:five>two?two:five);
}
