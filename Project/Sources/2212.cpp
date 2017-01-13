#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	long long ans=0;
	vector<int> sensors,score;
	int n,t,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		sensors.push_back(t);
	}
	sort(sensors.begin(),sensors.end());
	for(int i=1;i<n;i++)
		score.push_back(sensors[i]-sensors[i-1]);
	sort(score.begin(),score.end());
	for(int i=0;i<n-k;i++)
		ans+=score[i];
	printf("%lld\n",ans);
}
