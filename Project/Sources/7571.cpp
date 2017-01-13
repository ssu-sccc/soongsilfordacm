#include <stdio.h>
#include <vector>
#include <algorithm>
//int dotx[11111],doty[11111];
std::vector<int> dotx,doty;
int abs(int a)
{
	if(a<0) return a*-1;
	else return a;
}
int main()
{
	int n,m,sx,sy;
	long long ss=0;
	scanf("%d%d",&n,&m);	dotx.resize(m);	doty.resize(m);
	for(int i=0;i<m;i++)
		scanf("%d%d",&dotx[i],&doty[i]);
	std::sort(dotx.begin(),dotx.end());	std::sort(doty.begin(),doty.end());
	sx=dotx[(m-1)/2];	sy=doty[(m-1)/2];
	for(int i=0;i<m;i++)
	{
		ss+=abs(dotx[i]-sx);	ss+=abs(doty[i]-sy);
	}
	printf("%lld\n",ss);
}
