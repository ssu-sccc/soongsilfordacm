#include <algorithm>
#include <cstdio>

struct info {
	int age;
	char name[110];
	int index;
};

info arr[100010];

bool compar(info p, info q)
{
	if(p.age == q.age)
		return p.index < q.index;
	return p.age < q.age;
}

int main(void)
{
	int n, i;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		arr[i].index = i;
		scanf("%d %s", &arr[i].age, arr[i].name);
	}

	std::sort(arr, arr + n, compar);

	for(i = 0; i < n; i++)
		printf("%d %s\n", arr[i].age, arr[i].name);
	return 0;
}