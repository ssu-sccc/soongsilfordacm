#include <string.h>
#include <stdio.h>
int main()
{
	char a[55];
	int s=10,l;
	scanf("%s",a);	l=strlen(a);
	for(int i=1;i<l;i++)
	{
		if(a[i]==a[i-1]) s+=5;
		else s+=10;
	}
	printf("%d",s);
}
