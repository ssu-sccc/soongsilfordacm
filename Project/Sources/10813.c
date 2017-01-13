#include <stdio.h>
int main()
{
	int n,m,tmp,a,b;
	int ar[111];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		ar[i]=i;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		tmp=ar[a];	ar[a]=ar[b];	ar[b]=tmp;
	}
	
	for(int i=1;i<=n;i++)
		printf("%d ",ar[i]);
	printf("\n");
}
