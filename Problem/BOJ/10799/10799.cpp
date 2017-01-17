#include <cstdio>
#include <string.h>
#include<stdio.h>
using namespace std;

int a[100010];
char str[100010];

int main(void)
{
	int i, num = 0, j, size,sum = 0, n;

	scanf("%s", str);
	size = strlen(str);
	
	for (i = 0; i < size; i++)
	{
		if (str[i] == '(')
			num++;
		else
		{
			num--;
			if (str[i - 1] == '(')
				a[num]++;
			else
			{
				sum += a[num + 1] + 1;
				a[num] += a[num + 1];
				a[num + 1] = 0;
			}
		}
	}

	printf("%d\n", sum);

	return 0;

}