#include <stdio.h>
#include <list>
using namespace std;
int main()
{	int n,m;list<int> ar;list<int>::iterator p;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		ar.push_back(i);
	p=ar.begin();
	printf("<");
	for(int s=ar.size();s>1;s--)
	{
		for(int i=1;i<m;i++) if(++p==ar.end()) p=ar.begin();
		printf("%d, ",*p);
		p=ar.erase(p);
		if(p==ar.end()) p=ar.begin();
	}
	printf("%d>\n",ar.back());
}
