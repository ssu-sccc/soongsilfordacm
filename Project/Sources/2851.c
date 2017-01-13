#include <stdio.h>
int main()
{
	int s=0,t,a[10],i;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10&&s+a[i]<=100;i++)
		s+=a[i];
	if(i<9 && 100-s >= s+a[i+1] - 100)
		printf("%d\n",s+a[i+1]);
	else printf("%d\n",s);
}
