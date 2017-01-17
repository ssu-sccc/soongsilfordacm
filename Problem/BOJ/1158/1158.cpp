#include <stdio.h>
#include <list>

int main(void) {
	int n, m, k;
	scanf("%d %d", &n, &k);
	std::list<int> l;

	for (int i = 1; i <= n; i++)
		l.push_back(i);
	std::list<int>::iterator it = l.begin();

	printf("<");
	while (l.size() != 1)
	{
		for (int i = 1; i < k; i++) {
			if (it == l.end())
				it = l.begin();
			it++;
		}
		if (it == l.end())
			it = l.begin();
		printf("%d, ", *it);
		it = l.erase(it);
	}
	printf("%d>\n", *(l.begin()));
	return 0;
}