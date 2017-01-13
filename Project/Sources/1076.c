#include <stdio.h>
#include <string.h>
int main()
{
	int i; long long ans=0;
	char color[10][22]={"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
	char input[3][22];
	scanf("%s%s%s",input[0],input[1],input[2]);
	for(int j=1;j<=3;j++)
	{
		for(i=0;i<10;i++)
		{
			if(strcmp(color[i],input[j-1])==0) break;
		}
		switch(j)
		{
			case 1:
				ans+=i*10;
				break;
			case 2:
				ans+=i;
				break;
			case 3:
				for(int k=0;k<i;k++)
					ans*=10;
				break;
		}
	}
	printf("%lld\n",ans);
}
