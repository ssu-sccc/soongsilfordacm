#include <stdio.h>
int main()
{
	int n,two=0,five=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a=i,b=i;
		while(a%2==0){a/=2;two++;}
		while(b%5==0){b/=5;five++;}
	}
	printf("%d\n",two>five?five:two);
}
