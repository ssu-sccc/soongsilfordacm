#include <stdio.h>
int main()
{
	int n;
	for(scanf("%d",&n);n;scanf("%d",&n))
	{
		char dic[1111][111]={0};
		int j=0;
		scanf("\n");
		for(int i=0;i<n;i++)
			gets(dic[i]);
		for(int i=0;i<n;i++)
			for(;dic[i][j]!=' ' && dic[i][j]!=0;j++);
		printf("%d\n",j+1);
	}
}
