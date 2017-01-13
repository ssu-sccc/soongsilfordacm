#include <stdio.h>
int main()
{
	int r,c;
	char village[15][15]={0};
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++)
		scanf("%s",village[i]);
	for(int i=1;i<=r;i++)
		for(int j=0;j<r;j++)
		{
			if(village[i][j]=='.')
			{
				int cnt=0;
				if(village[i-1][j]=='.')	cnt++;
				if(village[i+1][j]=='.')	cnt++;
				if(village[i][j-1]=='.')	cnt++;
				if(village[i][j+1]=='.')	cnt++;
				if(cnt==1) {printf("1\n");	return 0;}
			}
		}
	printf("0\n");
}
