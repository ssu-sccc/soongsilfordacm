#include <stdio.h>
int main()
{
	int cnt=0,a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	while(a+b)
	{
		a+=b;
		if(a<c) break;
		cnt+=b=a/c;
		a%=c;
	}
	printf("%d\n",cnt);
}
