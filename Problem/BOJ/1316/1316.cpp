#include <stdio.h>
#include <string.h>

int arr[150];
char str[150];

int main(void) {
	int n, r = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		memset(arr, -1, sizeof(arr));
		bool flag = true;

		for (int j = 0; str[j] != '\0'; j++) {
			if (arr[str[j]] != -1 && arr[str[j]] + 1 != j)
				flag = false;
			arr[str[j]] = j;
		}

		if (flag)
			r++;
	}
	printf("%d\n", r);
}