#include <stdio.h>
#include <list>

char offer[1000010];

int main(void)
{
	int n;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%s", offer);
		std::list<char> lt;
		std::list<char>::iterator t = lt.begin();

		for(int j = 0; offer[j] != '\0'; j++)
		{
			if(offer[j] == '<')
			{
				if(t != lt.begin())
					t--;
			}
			else if(offer[j] == '>') {
				if(t != lt.end())
					t++;
			}
			else if(offer[j] == '-') {
				if(t != lt.begin()) {
					t--;
					t = lt.erase(t);
				}
			}
			else
			{
				t = lt.insert(t, offer[j]);
				t++;
			}
		}

		for(t = lt.begin(); t != lt.end(); t++)
			printf("%c", *t);
		printf("\n");
	}
	return 0;
}

