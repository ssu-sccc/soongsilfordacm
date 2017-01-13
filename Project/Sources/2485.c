#include <stdio.h>
int n,t[111111],cnt=0,ans=1;
int es(int a,int b)
{
	if(b)	return es(b,a%b);
	else return a;
}
int main()
{
	int tt;
	scanf("%d%d%d",&n,&t[0],&t[1]);	ans=t[1]-t[0];
	for(int i=2;i<n;i++)
	{
		scanf("%d",&t[i]);
		ans=es(t[i]-t[i-1],ans);
	}
	for(int i=1;i<n;i++)
		if(t[i]-t[i-1]>ans)
			cnt+=(t[i]-t[i-1])/ans-1;
	printf("%d\n",cnt);
}
