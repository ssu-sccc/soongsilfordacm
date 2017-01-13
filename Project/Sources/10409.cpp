#include <stdio.h>
int main()
{
	int n,T,t,s=0,i;
	scanf("%d%d",&n,&T);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		s+=t;
		if(s>T) break;
	}
	printf("%d\n",i);
}
