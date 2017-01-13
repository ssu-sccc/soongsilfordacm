#include <stdio.h>
int p[11111];
unsigned long long s=0;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			s+=p[i]>p[j]?p[i]-p[j]:p[j]-p[i];
	printf("%llu\n",s);


}
