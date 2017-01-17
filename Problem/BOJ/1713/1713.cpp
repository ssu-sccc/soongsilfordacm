#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>

struct info {
	int num;
	int where;
	int student;
	info(int num, int where, int student) : num(num), where(where), student(student) {}
};

std::vector<info> picture;

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int a;
		scanf("%d", &a);
		bool flag = false;
		for (int j = 0; j < picture.size() && !flag; j++) {
			if (picture[j].student == a) {
				flag = true;
				picture[j].num++;
			}
		}

		if (flag)
			continue;

		if (picture.size() < n)
			picture.push_back(info(0, i, a));
		else {
			int min1 = INT_MAX / 2, index;
			for (int j = 0; j < picture.size(); j++) {
				if (picture[j].num < min1) {
					min1 = picture[j].num;
					index = j;
				}
				else if (picture[j].num == min1 && picture[j].where < picture[index].where) {
					index = j;
				}
			}

			picture[index].num = 0, picture[index].where = i, picture[index].student = a;
		}
	}

	std::sort(picture.begin(), picture.end(), [](info a, info b) {
		return a.student < b.student;
	});
	for (int i = 0; i < picture.size(); i++)
		printf("%d ", picture[i].student);
	printf("\n");
}