#include <string.h>
#include <stdio.h>
int main()
{
	char month[15], months[13][15] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
	int day, year, hour, min,nmonth,sday=0;
	int days[] = { 0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int minutes=0,endyear=365*24*60;
	scanf("%s %d, %d %d:%d", month, &day, &year, &hour, &min);
	
	if (year % 400==0) { days[2] = 29; endyear += 24 * 60; }
	else if (year % 4==0 && year % 100) { days[2] = 29; endyear += 24 * 60; }

	for(int i=1;i<=12;i++)
		if (!strcmp(month, months[i])) { nmonth = i; break; }
	for (int i = 1; i < nmonth; i++)
		sday += days[i];
	minutes += sday * 24 * 60;
	minutes += (day-1) * 24 * 60;
	minutes += hour * 60 + min;
	printf("%.10Lf\n",(long double)minutes*100/(long double)endyear);
}
