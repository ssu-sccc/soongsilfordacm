#include <stdio.h>
#include <string.h>

int s(char str[]) {
	if (strcmp(str, "black") == 0)
		return 0;
	else if (strcmp(str, "brown") == 0)
		return 1;
	else if (strcmp(str, "red") == 0)
		return 2;
	else if (strcmp(str, "orange") == 0)
		return 3;
	else if (strcmp(str, "yellow") == 0)
		return 4;
	else if (strcmp(str, "green") == 0)
		return 5;
	else if (strcmp(str, "blue") == 0)
		return 6;
	else if (strcmp(str, "violet") == 0)
		return 7;
	else if (strcmp(str, "grey") == 0)
		return 8;
	else
		return 9;
}

long long pow1(int num) {
	long long r = 1;
	for (int i = 0; i < num; i++)
		r *= 10;
	return r;
}

int main(void) {
	char str[10];
	scanf("%s", str);
	int num1 = s(str);
	scanf("%s", str);
	int num2 = s(str);
	scanf("%s", str);
	int num3 = s(str);

	printf("%lld\n", (num1 * 10 + num2) * pow1(num3));
}