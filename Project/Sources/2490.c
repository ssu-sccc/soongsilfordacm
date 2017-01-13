#include <stdio.h>
int main()
{
	int t;	char q;
	for(int i=0;i<3;i++)
	{
		q=64;
		for(int j=0;j<4;j++)
		{
			scanf("%d",&t);	if(!t) q++;
		}
		printf("%c\n",q==64?'E':q);
	}
}
