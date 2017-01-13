#include <stdio.h>
int paper[111][111]={0};
int main()
{
	int n,a,b,s=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++)
				paper[a+j][b+k]=1;
	}
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			if(paper[i][j]) s++;
	printf("%d\n",s);
}
