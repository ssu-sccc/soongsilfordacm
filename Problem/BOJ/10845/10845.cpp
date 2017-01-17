#include <queue>
#include <cstdio>
#include <string.h>

int main(void)
{
	std::queue<int> q;
	int n, a;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		char op[6] = {0};
		scanf("%s", op);
		if(strcmp(op, "push") == 0)
		{
			scanf("%d", &a);
			q.push(a);
		}
		else if(strcmp(op, "pop") == 0)
		{
			if(q.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if(strcmp(op, "size") == 0)
			printf("%d\n", q.size());
		else if(strcmp(op, "empty") == 0)
			printf("%d\n", q.empty());
		else if(strcmp(op, "front") == 0)
		{
			if(q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.front());
		}
		else if(strcmp(op, "back") == 0)
		{
			if(q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.back());
		}
	}
	return 0;
}