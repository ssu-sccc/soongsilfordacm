#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int cn=1,left=0,n;
	vector<int> trophy;
	scanf("%d",&n);	trophy.resize(n);
	for(int i=0;i<n;i++)
		scanf("%d",&trophy[i]);
	for(int i=0;i<n;i++)
		if(trophy[i]>trophy[left]){left=i;cn++;}
	printf("%d\n",cn);	cn=1;	left=n-1;
	for(int i=n-1;i>=0;i--)
		if(trophy[i]>trophy[left]){left=i;cn++;}
	printf("%d\n",cn);
}
