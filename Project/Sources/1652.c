#include <stdio.h>
int main()
{
	char room[111][111];
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",room[i]);
	for(int i=0;i<n;i++)
	{
		int c=0;
		for(int j=0;j<n;j++)
		{
			if(room[i][j]=='.')
			{
				c++;
				if(c==2) ans++;
			}
			else c=0;
		}
	}
	printf("%d ",ans);
	ans=0;
	for(int i=0;i<n;i++)
	{
		int c=0;
		for(int j=0;j<n;j++)
		{
			if(room[j][i]=='.')
			{
				c++;
				if(c==2) ans++;
			}
			else c=0;
		}
	}
	printf("%d\n",ans);
}
