#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c,d;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	printf("%.3lf",sqrt((sqrt(b)+sqrt(d))*(sqrt(b)+sqrt(d))+(a-c)*(a-c)));
	return 0;
}