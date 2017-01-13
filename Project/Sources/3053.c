#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	printf("%.6Lf\n%.6lf\n",n*n*3.141592653589793238L,(n+n)*(n+n)/2.0);
}
