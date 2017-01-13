#include <stdio.h>
int main()
{
	int table[6][6]={0},s=0,pos[26][2],t,bingo=0,ans=0;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
		{scanf("%d",&t);	table[i][j]=t;	pos[t][0]=i;pos[t][1]=j;}
	for(int i=0;i<25;i++)
	{
		scanf("%d",&t);
		if(pos[t][0]==pos[t][1] && ++table[0][0]==5) bingo++;
		if(pos[t][0]+pos[t][1]==6 && ++s==5)	bingo++;
		if(++table[pos[t][0]][0]==5) bingo++;
		if(++table[0][pos[t][1]]==5) bingo++;
		if(!ans && bingo>=3)
		{
			ans=i+1;
		}
	}
	printf("%d\n",ans);
}
