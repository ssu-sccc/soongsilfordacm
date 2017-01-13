#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int main()
{
	int n,cnt=0;
	bool pass;
	char word[111];
	for(scanf("%d",&n);n--;)
	{	
		pass=true;
		int dic[27]={0},s;
		scanf("%s",word);		s=strlen(word);
		for(int i=0;i<s;i++)
			if(dic[word[i]-'a']++)
				if(word[i-1] != word[i])
				{
					pass=false;	break;
				}
		if(pass) cnt++;
	}
	printf("%d\n",cnt);
}
