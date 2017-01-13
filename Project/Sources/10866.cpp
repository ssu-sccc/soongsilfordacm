#include <list>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	char commands[8][20]={"push_front","push_back","pop_front","pop_back","size","empty","front","back"},input[500];
	int q,data,i;
	list<int> que;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",input);
		for(i=0;i<8;i++)
			if(strcmp(input,commands[i])==0) break;
		switch(i)
		{
			case 0:
				scanf("%d",&data);
				que.push_front(data);
				break;
			case 1:
				scanf("%d",&data);
				que.push_back(data);
				break;
			case 2:
				if(que.empty())	printf("-1\n");
				else{
				printf("%d\n",que.front());
				que.pop_front();}
				break;
			case 3:
				if(que.empty())	printf("-1\n");
				else{
				printf("%d\n",que.back());
				que.pop_back();}
				break;
			case 4:
				printf("%d\n",que.size());
				break;
			case 5:
				if(que.empty()) printf("1\n");
				else printf("0\n");
				break;
			case 6:
				if(que.empty()) printf("-1\n");
				else printf("%d\n",que.front());
				break;
			case 7:
				if(que.empty()) printf("-1\n");
				else printf("%d\n",que.back());
				break;
		}
	}


}
