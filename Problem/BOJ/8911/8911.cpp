#include <stdio.h>
#include <algorithm>

char str[510];
int move[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

int main(void) {
	int test;
	scanf("%d", &test);

	for (int t = 0; t < test; t++) {
		scanf("%s", str);
		int maxx = 0, maxy = 0, minx = 0, miny = 0;
		int curx = 0, cury = 0, dir = 0;


		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == 'F') {
				curx += move[dir][0];
				cury += move[dir][1];
			}
			else if (str[i] == 'B') {
				curx -= move[dir][0];
				cury -= move[dir][1];
			}
			else if (str[i] == 'L')
				dir = (dir + 1) % 4;
			else
				dir = (dir + 3) % 4;

			maxx = std::max(maxx, curx), minx = std::min(minx, curx);
			maxy = std::max(maxy, cury), miny = std::min(miny, cury);

		}

		printf("%d\n", (maxx - minx) * (maxy - miny));
	}
}