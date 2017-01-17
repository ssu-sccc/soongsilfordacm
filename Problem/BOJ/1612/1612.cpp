#include <stdio.h>
#include <string.h>

int result[1000010];
char tmp[10];
int input;
int r = -1, idx = 0;

int main(void) {
	scanf("%d", &input);
	
	int cur = 0;
	while (cur < 1000010) {
		bool flag = false;
		for (int i = cur; i <= idx && !flag; i++)
			if (result[i] != 1)
				flag = true;

		if (!flag) {
			r = idx + 1;
			break;
		}

		int t = -1;
		for (int i = 0; i <= 9; i++) {
			if (((input * i) % 10 + result[cur]) % 10 == 1) {
				t = i;
				break;
			}
		}
		if (t == -1) {
			r = -1;
			break;
		}
		sprintf(tmp, "%d", input * t);
		int len = strlen(tmp);

		for (int i = 0; i < len; i++) {
			result[cur + i + 1] += (result[cur + i] + tmp[len - i - 1] - '0') / 10;
			result[cur + i] = (result[cur + i] + tmp[len - i - 1] - '0') % 10;
		}
		
		if (cur + len - 1 >= idx) {
			if (result[cur + len] != 0)
				idx = cur + len;
			else
				idx = cur + len - 1;
		}
		else {
			for (int i = cur; i <= idx; i++) {
				result[i + 1] += result[i] / 10;
				result[i] = result[i] % 10;
			}
			if (result[idx + 1] > 0)
				idx++;
		}
		cur++;
	}

	printf("%d\n", r);
}