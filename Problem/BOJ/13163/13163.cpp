#include <stdio.h>
#include <string>

int main(void) {
	int test;
	scanf("%d", &test);
	getchar();
	for (int t = 0; t < test; t++) {
		std::string r;
		bool flag = false;
		char c;
		while ((c = getchar()) != '\n') {
			if (c == ' ') {
				if (!flag)
					r.push_back('g'), r.push_back('o'), r.push_back('d');
				flag = true;
			}
			if (flag && c != ' ')
				r.push_back(c);
		}
		printf("%s\n", r.c_str());
	}
}