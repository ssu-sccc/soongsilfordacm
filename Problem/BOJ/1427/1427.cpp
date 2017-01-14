#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>

int main(void) {
	std::string a;
	std::cin >> a;
	std::sort(a.begin(), a.end());
	for (auto it = a.rbegin(); it != a.rend(); it++)
		printf("%c", *it);
	printf("\n");
}