#include <stdio.h>
int main()
{
	int t,i;
	bool once;
	char name[111];
	for(scanf("%d\n",&t);t--;)
	{
		i=0;gets(name);
		printf("god");
		while(name[i]!=' ') i++;
		while(name[i]!='\0') if(name[i++]!=' ') putchar(name[i-1]);
		putchar('\n');
	}
}
