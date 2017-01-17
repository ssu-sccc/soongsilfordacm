#include <stdio.h>
#include <vector>

std::vector<char> arr[5];
int number[5];
std::vector<char> result;

int main(void) {
	int n = 0;
	char c;

	while ((c = getchar()) != EOF) {
		if (c == '\n')
			n++;
		else
			arr[n].push_back(c);
	}

	while (1) {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (number[i] < arr[i].size()) {
				result.push_back(arr[i][number[i]++]);
				flag = true;
			}
		}
		if (!flag)
			break;
	}
	for (int i = 0; i < result.size(); i++)
		printf("%c", result[i]);
}