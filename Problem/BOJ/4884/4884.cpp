#include <stdio.h>

int main(void)
{
	while (1)
	{
		unsigned long long g, t, a, d, c = 1, team;

		scanf("%llu %llu %llu %llu", &g, &t, &a, &d);
		if (g == -1)
			break;
		printf("%llu*%llu/%llu+%llu=", g, a, t, d);
		team = (g * a) + d;

		while (team > c)
			c *= 2;
		team = c - team;
		t = (t * (t - 1)) / 2;
		unsigned long long x = (g * t) + c - 1;

		printf("%llu+%llu\n", x, team);
	}
	return 0;
}