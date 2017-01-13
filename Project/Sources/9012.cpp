#include <stack>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	char input[55];
	int T,n;
	for(scanf("%d",&T);T--;)
	{
		stack<char> s;
		bool chk=false;
		scanf("%s",input);
		n=strlen(input);
		for(int i=0;i<n;i++)
			if(chk)
				break;
			else
			switch(input[i])
			{
				case '(':
					s.push(64);
					break;
				case ')':
					if(s.empty())
					{
						chk=true;
						break;
					}
					else
						s.pop();
					break;
			}
		if(!chk && s.empty()) printf("YES\n");
			else printf("NO\n");
	}
}
