#include <stdio.h>
int n;
int gogo(char coin[22][22],char status[])
{
	int ss[22]={0};
	for(int i=0;i<n;i++)
	{
		if(status[i]=='1')
		{
			for(int j=0;j<n;j++)
				coin[i][j]=coin[i][j]=='H'?'T':'H';
		}
	}
}
int main()
{
	scanf("%d",&n);	int score=n*n+1;
	char coin[22][22],status[20]={"00000000000000000000"};
	for(int i=1;i<=n;i++)
		scanf("%s",coin[i]);
	int j;
	while(1)
	{
		while(j<n)
		{
			if(status[j]=='0')
			{	status[j]='1';	break;}
			else
			{ status[j]='0';	j++;}
		}
		if(j>=n) break;
		int t=gogo(coin,status);
		if(t<score) t=score;
	}
	printf("%d\n",score);
}
