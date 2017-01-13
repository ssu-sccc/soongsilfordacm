#include <stdio.h>
#include <stdbool.h>
char ans[]={"111"};
bool step()
{
	if(ans[2]=='9')
		if(ans[1]=='9')
			if(ans[0]=='9') return false;
			else {ans[2]='1';	ans[1]='1'; ans[0]++;}
		else {ans[2]='1'; ans[1]++;}
	else ans[2]++;
	if(ans[2]==ans[1] || ans[1]==ans[0] || ans[2] == ans[0]) return step();
	else return true;
}
int main()
{
	int cnt=0,n,es[100],eb[100];
	char eans[100][5];
	bool pass;
	scanf("%d\n",&n);
	for(int i=0;i<n;i++)
		scanf("%s%d%d",eans[i],&es[i],&eb[i]);
	while(step())
	{
		pass=true;
//		printf("%s ::\n",ans);
		for(int i=0;i<n;i++)
		{
			int s=0,b=0;
			for(int j=0;j<3;j++)	if(eans[i][j]==ans[j]) s++;
			printf("\t%s:",eans[i]);
			if(ans[0]==eans[i][1] || ans[0]==eans[i][2]) b++;
			if(ans[1]==eans[i][0] || ans[1]==eans[i][2]) b++;
			if(ans[2]==eans[i][0] || ans[2]==eans[i][1]) b++;
			if(b!=eb[i]||s!=es[i]) pass=false;
//			printf(" s%d b%d = s%d b%d\n",es[i],eb[i],s,b);
		}
		if(pass) cnt++;
	}
	printf("%d\n",cnt);
}
