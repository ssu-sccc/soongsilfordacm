#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	string input;
	cin>>input;
	int	s=input.length();
	for(int i=0;i<s;i++)
	{
		printf("%c",input[i]);
		if((i+1)%10==0) printf("\n");
	}
	if(s%10) printf("\n");
}
