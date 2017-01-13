#include <stdio.h>
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,ss=0,ts;
		float sg=0,tg;
		for(scanf("%d",&n);n--;)
		{
			scanf("%d %f",&ts,&tg);
			ss+=ts;	sg+=tg*ts;
		}
		printf("%d %.1f\n",ss,sg/ss);
	}
}
