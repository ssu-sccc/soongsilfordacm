#include <stdio.h>
int main()
{
	int T,s[1000];
	for(scanf("%d",&T);T--;)
	{
		int n,ss=0,cnt=0,avg;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&s[i]);
			ss+=s[i];
		} avg=(double)ss/n;
		for(int i=0;i<n;i++)
		{
			if(avg<s[i]) cnt++;
		}
		printf("%.3lf%%\n",(double)cnt/n*100);
	}
}
