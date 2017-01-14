#include <stdio.h>

int arr[5][5];
bool check[5][5];

bool OK(void) {
	int n = 0;
	for (int i = 0; i < 5; i++) {
		bool flag = false;
		for (int j = 0; j < 5; j++)
			if (check[i][j] == false)
				flag = true;
		if (!flag)
			n++;
	}

	for (int i = 0; i < 5; i++) {
		bool flag = false;
		for (int j = 0; j < 5; j++)
			if (check[j][i] == false)
				flag = true;
		if (!flag)
			n++;
	}

	if (check[0][0] == true && check[1][1] == true && check[2][2] == true && check[3][3] == true && check[4][4] == true)
		n++;
	if (check[0][4] == true && check[1][3] == true && check[2][2] == true && check[3][1] == true && check[4][0] == true)
		n++;

	if (n >= 3)
		return true;
	else
		return false;
}

int main(void) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0; i < 25; i++) {
		int a;
		scanf("%d", &a);

		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (a == arr[j][k])
					check[j][k] = true;
			}
		}
		if (OK()) {
			printf("%d\n", i + 1);
			break;
		}
	}
}