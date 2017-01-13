#include <stdio.h>
int main()
{
	int a;
//	printf(">%d\n",(int)&a/8);
	if (((int)(&a)/8)%2) printf("Yonsei\n");
	else printf("Korea\n");
}
