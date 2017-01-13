#include <stdio.h>
#include <string.h>
#include <algorithm>
int main()
{
	char s[22];	int l;
	scanf("%s",s);	l=strlen(s);
	std::sort(s,s+l);
	for(int i=l-1;i>=0;i--)
		printf("%c",s[i]);
}
