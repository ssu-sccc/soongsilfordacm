#include <stdio.h>
int main()
{
	while(1)
	{
		int n,p;
		if(scanf("%d%d",&n,&p)==1) break;

		if(p<=n/2)
			if(p%2)
				printf("%d %d %d\n",p+1,n-p,n-p+1);
			else
				printf("%d %d %d\n",p-1,n-p+1,n-p+2);
		else
			if(p%2)
				printf("%d %d %d\n",n-p,n-p+1,p+1);
			else
				printf("%d %d %d\n",n-p+1,n-p+2,p-1);
	}
}
