#include <stdio.h>
#include <string.h>
int s=0;
char ans[55];
void step()
{
		for(int i=1;i<=s;i++)
			if(ans[i]>ans[i-1]+1)
			{
				ans[i-1]++;
				for(int j=i-2;j>=0;j--)
					ans[j]=j+'0';
				return;
			}
		if(ans[s]++ =='9')
		{
			s++;	ans[s]=s+'0';
		}
		for(int i=0;i<s;i++)
			ans[i]=i+'0';
}
int main()
{
	int n=0;	scanf("%d",&n);
	ans[0]='0';	
	while(--n)	if(strcmp(ans,"0123456789")!=0) step(); else break;
/*	while(++n)
	if(strcmp(ans,"0123456789")!=0) 
	{
		step();
		printf("%d\t",n);
		for(int i=s;i>=0;i--)
			printf("%c",ans[i]);
		printf("\n");
	} else break;
*/
	if(!n)
		for(int i=s;i>=0;i--)
			printf("%c",ans[i]);
	else
		printf("-1");
}
