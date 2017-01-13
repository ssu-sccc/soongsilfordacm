#include <vector>
#include <cmath>
#include <stdio.h>
using  namespace std;
int main()
{
	int g, s;
	vector<int> ans;
	scanf("%d", &g);
	s = sqrt(g);
	for (int i = 1; i <= s; i++)
		if (g%i == 0 && (i + g / i) % 2 == 0 && i!=g/i) ans.push_back((i + g / i) / 2);
	if (ans.empty())	printf("-1\n");
	else
		for (vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); ++it)
			printf("%d\n", *it);
}
