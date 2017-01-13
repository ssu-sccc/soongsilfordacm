#include <stdio.h>
long long init[200014];	unsigned long long ans=1;
char q[300000];
int main()
{
	int n,k,x=1,y=1;	init[1]=1;
//	scanf("%d%d\n%s",&n,&k,q);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		init[i+1]=init[i]+i;
	for(int i=n;i>1;i--)
		init[n+n-i+1]=init[n+n-i]+i;
	for(int i=1;i<=n+n;i++)
		printf("%d ",init[i]);
	printf("\n");

	for(int y=1;y<=n;y++)
	{
		for(int x=1;x<=n;x++)
		{
			if(x+y<=n+1)
				if((x+y)%2)
				{//	printf("%d\n",init[x+y-1]+y-1);
					ans=init[x+y-1]+y-1;}
				else
				{//	printf("%d\n",init[x+y-1]+x-1);
					ans=init[x+y-1]+x-1;}
			else
				if((x+y)%2)
				{//	printf("%d\n",init[x+y-1]+y-1);
					ans=init[x+y-1]+y-(x+y-n);}
				else
				{//	printf("%d\n",init[x+y-1]+x-1);
					ans=init[x+y-1]+x-(x+y-n);}
				
	
			printf("\t%lld",ans);
		}
		printf("\n");
	}
/*	for(int i=0;i<k;i++)
	{
		switch(q[i])
		{
			case 'U': y--; break;
			case 'D': y++; break;
			case 'L': x--; break;
			case 'R': x++; break;
		}
		if(x+y<=n+1)
			if((x+y)%2)
			{	//printf("%d\n",init[x+y-1]+y-1);
				ans+=init[x+y-1]+y-1;}
			else
			{//	printf("%d\n",init[x+y-1]+x-1);
				ans+=init[x+y-1]+x-1;}
		else
			if((x+y)%2)
			{//	printf("%d\n",init[x+y-1]+y-1);
				ans=init[x+y-1]+y-(x+y-n);}
			else
			{//	printf("%d\n",init[x+y-1]+x-1);
				ans=init[x+y-1]+x-(x+y-n);}

	}
	printf("%llu\n",ans);*/
}
