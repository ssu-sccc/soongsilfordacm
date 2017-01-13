#include <stdio.h>
#include <math.h>
int main()
{
	int n,w,h,s,t;
	scanf("%d%d%d",&n,&w,&h);
	s=(int)sqrt((float)w*w+h*h);
	while(n--)
	{
		scanf("%d",&t);
		if(t<=s) printf("DA\n");
		else printf("NE\n");
	}
}
