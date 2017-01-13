#include <stdio.h>
#include <queue>
#include <functional>
using namespace std;
int main()
{
	priority_queue<int,vector<int>,greater<int> > g;
	int n,t;
	for(scanf("%d",&n);n--;)
	{
		scanf("%d",&t);
		g.push(t);
	}
	while(!g.empty())
	{
		printf("%d\n",g.top());	g.pop();
	}
}
