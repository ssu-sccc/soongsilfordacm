#include <stdio.h>
#include <algorithm>
long long in[1000009],maxc,cntc;
int maxx=0,cntx;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",&in[i]);
	std::sort(in,in+n);

	maxc=cntc=in[0];maxx=cntx=1;
	for(int i=1;i<n;i++)
	{
		if(cntc!=in[i])
		{
			if(cntx>maxx)	{ maxc=cntc;	maxx=cntx;}
			cntc=in[i];	cntx=1;
		}
		else
			cntx++;
	}
	if(cntx>maxx)	maxc=in[n-1];
	printf("%lld\n",maxc);
}
