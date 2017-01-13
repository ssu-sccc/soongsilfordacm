#include <stdio.h>
#include <string>
#include <set>
using namespace std;
int main()
{
	int n,m;
	char names[22]; string input;	
	set<string> hear,ans;	set<string>::iterator c;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",names);	input=names;
		hear.insert(input);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%s",names);	input=names;
		if(hear.find(input)!=hear.end()) ans.insert(input);
	}
	printf("%d\n",ans.size());
	for(c=ans.begin();c!=ans.end();++c)
		printf("%s\n",(*c).c_str());
}
