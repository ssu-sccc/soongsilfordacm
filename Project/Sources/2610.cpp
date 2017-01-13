#include <stdio.h>
#include <queue>
#include <functional>
#define INF 100000
using namespace std;
int map[105][105],cost[105],connected[105]={0},connect=0;priority_queue<int,vector<int>,greater<int> > ans;
int main()
{
	int n,m,a,b,minn=INF,minm;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
			map[i][j]=INF;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		map[a][b]=1;
		map[b][a]=1;
	}
	for(int i=1;i<=n;i++)
		map[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(map[j][k]>map[j][i]+map[i][k]) map[j][k]=map[j][i]+map[i][k];
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(map[i][j]>cost[i])
					cost[i]=map[i][j];
	while(connect<n)
	{
		minn=INF;
		for(int i=1;i<=n;i++)
			if(cost[i]<minn && connected[i]==0)	{ minn=cost[i];	minm=i;}
		ans.push(minm);
		for(int i=1;i<=n;i++)
			if(map[minm][i]<INF)
			{
				connect++;
				connected[i]=1;
			}
	}
	printf("%d\n",ans.size());
	while(!ans.empty())
	{
		printf("%d\n",ans.top());
		ans.pop();
	}
}
