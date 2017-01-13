#include <stdio.h>
#include <stdbool.h>
int main()
{
	int T,tri[50];
	int	t=1,s=t;
	while(s<=1000)
	{
		tri[t-1]=s;
		s+=++t;
	}
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&t);
		bool pass=false;
		for(int i=0;i<44&&!pass;i++)
			for(int j=0;j<44&&!pass;j++)
				for(int k=0;k<44;k++)
					if(tri[i]+tri[j]+tri[k]==t){pass=true; break;}
		printf("%d\n",pass?1:0);
	}
}
