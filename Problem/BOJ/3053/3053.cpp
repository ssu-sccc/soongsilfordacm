#include <stdio.h>
#define PI 3.14159265358979323846

int main(void) {
	double n;
	scanf("%lf", &n);

	printf("%.6lf\n%.6lf\n", n * n * PI, 2.0 * n * n);
	return 0;
}