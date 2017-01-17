#include <queue>
#include <functional>
#include <cstdio>

using namespace std;

priority_queue<int, vector<int>, greater<int> > m;

int main(void)
{
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		if(a == 0)
		{
			if(m.empty())
				printf("0\n");
			else
			{
				printf("%d\n", m.top());
				m.pop();
			}
		}
		else
			m.push(a);
	}
	return 0;
}
