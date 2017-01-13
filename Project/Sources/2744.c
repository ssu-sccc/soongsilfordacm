#include <string.h>
main(s,i)
{
	char word[111];
	scanf("%s",word);
	for(s=strlen(word),i=0;i<s;i++)
		if(word[i]>96) word[i]-=32;
		else word[i]+=32;
	printf("%s\n",word);
}
