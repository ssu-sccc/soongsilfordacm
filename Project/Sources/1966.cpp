#include <queue>
#include <stdio.h>
using namespace std;
typedef pair<int,int> P;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,m,t,mp;
		queue<P> lol;
		priority_queue<int> pri; 
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			if(i==m) mp=t;
			lol.push({t,i});	pri.push(t);
		}
		t=1;
		while(1)
		{
			if(pri.top()==lol.front().first)
			{
				if(lol.front().second==m)
				{
					printf("%d\n",t);
					break;
				}
				t++;
				pri.pop();
				lol.pop();
			}
			else if(pri.top()>lol.front().first)
			{
				lol.push(lol.front());
				lol.pop();
			}
		}
	}
}
