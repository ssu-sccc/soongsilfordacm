#include <stdio.h>
int main()
{
	int h=0,n,b=1,bb=0;
	scanf("%d",&n);
	while(1)
	{
		if(n-b<0) break;
		h++;	n-=b;
		b=b+(++bb)*4;
	}
	printf("%d\n",h);
}
