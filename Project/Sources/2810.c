#include <stdio.h>
char input[55];
int n;
int main()
{
	int i,s=0;
	scanf("%d\n%s",&n,input);
	for(i=0;i<n;i++)
		if(input[i]=='L') s++;
	printf("%d\n",s>2?n-(s/2)+1:n);
}
