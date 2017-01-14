#include <stdio.h>
#include <set>
#include <algorithm>

std::multiset<int> set;

int main(void) {
	int test;
	scanf("%d", &test);

	for (int t = 0; t < test; t++) {
		set.clear();

		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			char c;
			int a;
			scanf(" %c %d", &c, &a);

			if (c == 'I') 
				set.insert(a);
			else {
				if (set.size() != 0){
					if (a == -1)
						set.erase(set.begin());
					else
						set.erase(std::prev(set.end()));
				}
			}
		} 

		if (set.size() == 0)
			printf("EMPTY\n");
		else
			printf("%d %d\n", *(std::prev(set.end())), *(set.begin()));
	}
}