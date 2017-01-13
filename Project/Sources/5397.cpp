#include <stdio.h>
#include <string>
#include <iostream>
#include <list>
using namespace std;
string input;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		input.clear();
		int s;	list<char> ans; list<char>::iterator cursor;
		cin>>input;
		s=input.length();	cursor=ans.begin();
		for(int i=0;i<s;i++)
		{
			switch(input[i])
			{
				case '<':
					if(cursor!=ans.begin()) cursor--;
					break;
				case '>':
					if(cursor!=ans.end())	cursor++;
					break;
				case '-':
					if(!ans.empty() && cursor!=ans.begin()) cursor=ans.erase(--cursor);
					break;
				default :
					ans.insert(cursor,input[i]);

			}
		//	char a;
		//	if(cursor==ans.end()) a='E';	else if(cursor==ans.begin()) a='B';	else a=*cursor;
		/*	list<char>::iterator cc;
			for(cc=ans.begin();cc!=ans.end();++cc)
				              printf("%c",*cc);
			printf("\n");*/

		}
		//printf("%d: %s\n",s,&input[s-5]);
		for(cursor=ans.begin();cursor!=ans.end();++cursor)
			printf("%c",*cursor);
		printf("\n");
	}
}
