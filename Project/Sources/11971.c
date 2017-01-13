#include <stdio.h>
int main()
{
	int n,m,a,b,r=0,score=0,j,i;
	int road[111];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		for(j=0;j<a;j++)
		{
			road[j+r]=b;
		}
		r+=j;
	}
	r=0;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		for(j=0;j<a;j++)
			if(score<b-road[j+r])	score=b-road[j+r];
		r+=j;
	}
	printf("%d\n",score);
}
