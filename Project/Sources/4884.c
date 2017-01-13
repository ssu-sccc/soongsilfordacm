#include <stdio.h>
int main()
{
	while(1)
	{
		long long g,a,t,d; unsigned long long x=0,y=0;
		scanf("%lld%lld%lld%lld",&g,&t,&a,&d);
		if(g+a+t+d<0) break;
		unsigned long long i,tt=g*a+d;
		for(i=1;i<tt;i*=2);
		y=i-tt;	x+=i-1;
		x+=g*((t*(t-1))/2);
		printf("%lld*%lld/%lld+%lld=%llu+%llu\n",g,a,t,d,x,y);
	}
}
