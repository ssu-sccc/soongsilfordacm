#include <stdio.h>
int main()
{
	int hamburger=4444,berverage=4444,a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	hamburger=a>b?(b>c?c:b):a>c?c:a;
	scanf("%d%d",&a,&b);
	berverage=a>b?b:a;
	printf("%d\n",hamburger+berverage-50);
}
