#include <stdio.h>
#include <unordered_map>
#include <string>
#include <iostream>
#include <set>

std::unordered_map<std::string, bool> map;
std::set<std::string> result;
int main(void) {
	int n, m;
	std::string buffer;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		std::cin >> buffer;
		map[buffer] = true;
	}

	for (int i = 1; i <= m; i++) {
		std::cin >> buffer;
		if (map[buffer])
			result.insert(buffer);
	}
	printf("%d\n", result.size());

	for (auto it = result.begin(); it != result.end(); it++)
		printf("%s\n", it->c_str());
}