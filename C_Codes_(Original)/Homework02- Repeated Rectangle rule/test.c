#include<stdio.h>
#include <math.h>

double function(double x)\
{
	return pow(x,3.0)*pow((1+pow(x,4.0)),3.0);
}

double simpson(interval, upper_limit, lower_limit)
double upper_limit, lower_limit;
int interval;
{
	int interval;
	float a, h, s1, s2, s3, sum;

	h = (upper_limit - lower_limit) /  (interval *1.0);

	s1 = function(upper_limit) + function(lower_limit);
	s2 = 0;

	for (int i = 1; i <= interval; i=i+2)
	{
		s2 = s2 + 4*function(lower_limit+i*h);
	}

	s3=0;
	for (int i = 2; i <= interval; i=i+2)
	{
		s3 = s3 + 2*function(a+i*h);
	}

	sum = (s1 + s2 + s3)* h/3;

return sum;
}

int main(int argc, char const *argv[])
{
	double simpson();
	double result;
	double upper_limit= 1.0, lower_limit= 0.0;
	int interval = 4;

	result = simpson(interval, upper_limit, lower_limit)

	fprintf(stdout, "The result of integral using simpson rule is: %f\n", result);
	return 0;
}