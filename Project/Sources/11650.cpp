#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
int main()
{
	vector<pair<int,int> > ar;
	int n,a,b;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		ar.push_back({a,b});
	}
	sort(ar.begin(),ar.end());
	for(int i=0;i<n;i++)
		printf("%d %d\n",ar[i].first,ar[i].second);
}
