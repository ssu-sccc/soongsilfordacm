#include <stdio.h>
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int n,a=1,b=1,c=1,t;
	scanf("%d%d%d",&n,&a,&b);
	t=gcd(a,b);
	if(n==3) {scanf("%d",&c);
	t=gcd(b,c);}

	for(int i=1;i<=t;i++)
	{
		if(t%i==0) printf("%d\n",i);
	}
}
