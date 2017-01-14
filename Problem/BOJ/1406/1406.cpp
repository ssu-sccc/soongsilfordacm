#include <stdio.h>
#include <list>

std::list<int> list;
char buffer[100010];

int main(void) {
	int n;
	scanf("%s", buffer);

	for (int i = 0; buffer[i] != '\0'; i++)
		list.push_back(buffer[i]);
	
	auto cur = list.end();
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		char type;
		scanf(" %c", &type);

		if (type == 'P') {
			char c;
			scanf(" %c", &c);
			list.insert(cur, c);
		}
		else if (type == 'D') {
			if (cur != list.end())
				cur++;
		}
		else if (type == 'L') {
			if (cur != list.begin())
				cur--;
		}
		else if (type == 'B') {
			if (cur != list.begin()) {
				cur--;
				cur = list.erase(cur);
			}
		}
	}

	for (auto it = list.begin(); it != list.end(); it++)
		printf("%c", *it);
	printf("\n");
}