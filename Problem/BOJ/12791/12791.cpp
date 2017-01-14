
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<cfloat>
#include<limits.h>
#include<vector>
#include<math.h>
#include<string>
#include<functional>
using namespace std;

vector<string> arr[3000];

int main()
{
	arr[1967].push_back("DavidBowie");
	arr[1969].push_back("SpaceOddity");
	arr[1970].push_back("TheManWhoSoldTheWorld");
	arr[1971].push_back("HunkyDory");
	arr[1972].push_back("TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
	arr[1973].push_back("AladdinSane");
	arr[1973].push_back("PinUps");
	arr[1974].push_back("DiamondDogs");
	arr[1975].push_back("YoungAmericans");
	arr[1976].push_back("StationToStation");
	arr[1977].push_back("Low");
	arr[1977].push_back("Heroes");
	arr[1979].push_back("Lodger");
	arr[1980].push_back("ScaryMonstersAndSuperCreeps");
	arr[1983].push_back("LetsDance");
	arr[1984].push_back("Tonight");
	arr[1987].push_back("NeverLetMeDown");
	arr[1993].push_back("BlackTieWhiteNoise");
	arr[1995].push_back("1.Outside");
	arr[1997].push_back("Earthling");
	arr[1999].push_back("Hours");
	arr[2002].push_back("Heathen");
	arr[2003].push_back("Reality");
	arr[2013].push_back("TheNextDay");
	arr[2016].push_back("BlackStar");

	int test;
	scanf("%d", &test);

	for (int t = 0; t < test; t++) {
		int num = 0, s, e;
		scanf("%d %d", &s, &e);
		for (int i = s; i <= e; i++)
			num += arr[i].size();
		printf("%d\n", num);

		for (int i = s; i <= e; i++) {
			for (int j = 0; j < arr[i].size(); j++) {
				printf("%d %s\n", i, arr[i][j].c_str());
			}
		}
	}
	return 0;
}