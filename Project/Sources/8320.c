#include <stdio.h>
int main()
{
	int n,c=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i*j<=n) c++;
	for(int i=1;i*i<=n;i++)
		c++;
	printf("%d\n",c/2);
}
