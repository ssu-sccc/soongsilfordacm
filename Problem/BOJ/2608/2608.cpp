#include <stdio.h>

char str1[110], str2[110];
int change(char c) {
	if (c == 'I')
		return 1;
	if (c == 'V')
		return 5;
	if (c == 'X')
		return 10;
	if (c == 'L')
		return 50;
	if (c == 'C')
		return 100;
	if (c == 'D')
		return 500;
	if (c == 'M')
		return 1000;
	return 0;
}

void ch(int num) {
	if (num / 1000 != 0) {
		for (int i = 0; i < num / 1000; i++)
			printf("M");
		num %= 1000;
	}
	if (num / 900 != 0) {
		printf("CM");
		num %= 900;
	}
	if (num / 500 != 0) {
		printf("D");
		num %= 500;
	}
	if (num / 400 != 0) {
		printf("CD");
		num %= 400;
	}
	if (num / 100 != 0) {
		for (int i = 0; i < num / 100; i++)
			printf("C");
		num %= 100;
	}
	if (num / 90 != 0) {
		printf("XC");
		num %= 90;
	}
	if (num / 50 != 0) {
		printf("L");
		num %= 50;
	}
	else if (num / 40 != 0) {
		printf("XL");
		num %= 40;
	}
	if (num / 10 != 0) {
		for (int i = 0; i < num / 10; i++)
			printf("X");
		num %= 10;
	}
	if (num / 9 != 0) {
		printf("IX");
		num %= 9;
	}
	if (num / 5 != 0) {
		printf("V");
		num %= 5;
	}
	if (num / 4 != 0) {
		printf("IV");
		num %= 4;
	}
	if (num != 0) {
		for (int i = 0; i < num; i++)
			printf("I");
	}
}

int main(void) {
	scanf("%s %s", str1, str2);
	int hash = 0;
	for (int i = 0; str1[i] != '\0'; i++) {
		if (change(str1[i]) < change(str1[i + 1]))
			hash -= change(str1[i]);
		else
			hash += change(str1[i]);
	}

	for (int i = 0; str2[i] != '\0'; i++) {
		if (change(str2[i]) < change(str2[i + 1]))
			hash -= change(str2[i]);
		else
			hash += change(str2[i]);
	}

	printf("%d\n", hash);
	ch(hash);
	printf("\n");
}