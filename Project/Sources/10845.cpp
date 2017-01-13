#include <list>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	char commands[6][10]={"push","pop","size","empty","front","back"},input[500];
	int q,data,i;
	list<int> que;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",input);
		for(i=0;i<6;i++)
			if(strcmp(input,commands[i])==0) break;
		switch(i)
		{
			case 0:
				scanf("%d",&data);
				que.push_back(data);
				break;
			case 1:
				if(que.empty())	printf("-1\n");
				else{
				printf("%d\n",que.front());
				que.pop_front();}
				break;
			case 2:
				printf("%d\n",que.size());
				break;
			case 3:
				if(que.empty()) printf("1\n");
				else printf("0\n");
				break;
			case 4:
				if(que.empty()) printf("-1\n");
				else printf("%d\n",que.front());
				break;
			case 5:
				if(que.empty()) printf("-1\n");
				else printf("%d\n",que.back());
				break;
		}
	}


}
