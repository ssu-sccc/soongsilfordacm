#include <deque>
#include <cstdio>
#include <string.h>

std::deque<int> de;

int main(void)
{
	int n, a;
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		char op[12] = {0};
		scanf("%s", op);

		if(strcmp(op, "push_back") == 0)
		{
			scanf("%d", &a);
			de.push_back(a);
		}
		else if(strcmp(op, "push_front") == 0)
		{
			scanf("%d", &a);
			de.push_front(a);
		}
		else if(strcmp(op, "pop_front") == 0)
		{
			if(de.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", de.front());
				de.pop_front();
			}
		}
		else if(strcmp(op, "pop_back") == 0)
		{
			if(de.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", de.back());
				de.pop_back();
			}
		}
		else if(strcmp(op, "size") == 0)
			printf("%d\n", de.size());
		else if(strcmp(op, "empty") == 0)
			printf("%d\n", de.empty());
		else if(strcmp(op, "front") == 0)
		{
			if(de.empty())
				printf("-1\n");
			else
				printf("%d\n", de.front());
		}
		else if(strcmp(op, "back") == 0)
		{
			if(de.empty())
				printf("-1\n");
			else
				printf("%d\n", de.back());
		}
	}
	return 0;
}