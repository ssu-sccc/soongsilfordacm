#include <string>
#include <stdio.h>
#include <map>
using namespace std;
int main()
{
	int T;
	multimap<int,string> album;
	album.insert({1967,"DavidBowie"});
	album.insert({1969,"SpaceOddity"});
	album.insert({1970,"TheManWhoSoldTheWorld"});
	album.insert({1971,"HunkyDory"});
	album.insert({1972,"TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"});
	album.insert({1973,"AladdinSane"});
	album.insert({1973,"PinUps"});
	album.insert({1974,"DiamondDogs"});
	album.insert({1975,"YoungAmericans"});
	album.insert({1976,"StationToStation"});
	album.insert({1977,"Low"});
	album.insert({1977,"Heroes"});
	album.insert({1979,"Lodger"});
	album.insert({1980,"ScaryMonstersAndSuperCreeps"});
	album.insert({1983,"LetsDance"});
	album.insert({1984,"Tonight"});
	album.insert({1987,"NeverLetMeDown"});
	album.insert({1993,"BlackTieWhiteNoise"});
	album.insert({1995,"1.Outside"});
	album.insert({1997,"Earthling"});
	album.insert({1999,"Hours"});
	album.insert({2002,"Heathen"});
	album.insert({2003,"Reality"});
	album.insert({2013,"TheNextDay"});
	album.insert({2016,"BlackStar"});
	for(scanf("%d",&T);T--;)
	{
		int s,e,a=0;
		scanf("%d%d",&s,&e);
		for(int i=s;i<=e;i++)
			a+=album.count(i);
		printf("%d\n",a);
		for(int i=s;i<=e;i++)
		{
			auto c=album.equal_range(i);
			for(auto it=c.first;it!=c.second;++it)
				printf("%d %s\n",(*it).first,(*it).second.c_str());
		}
	}
}
