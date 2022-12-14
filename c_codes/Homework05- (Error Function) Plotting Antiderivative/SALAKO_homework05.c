#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	//The following code prints out the x value and the associative error function

	//created a file pointer called fpout
	FILE *fpout;

	// used the file pointer to create and write a new file 'SALAKO.out'
	fpout = fopen("SALAKO.out", "w");
	
	// declaring the error function and other necessary variables
	double error_function();
	double lower_limit = 0.0, upper_limit = 3.0;

	for (double xpoint = 0.0; xpoint <= upper_limit+0.02; xpoint = xpoint+0.02)
	{
		fprintf(fpout, "%.3f %.6f\n", xpoint, error_function(xpoint));
	}

	fclose(fpout);

	return 0;
}

double error_function(x)
double x;
{
	//The x is the upperbound of the integral being iterated!

	//declaration of function
	int interval = 2;
	int keep_going = 1;
	double sum_prev = 0.0; // TO be used to store the preciding sum.
	double lower_limit = 0.0, upper_limit = x;

	while(keep_going)
	{
		double h, sum_f_l, sum_odd, sum_even, sum, check, eps, s, diff;

		h = (upper_limit - lower_limit) /  (interval *1.0);
		// the distance between each nodes

		sum_f_l = exp(-1.0*upper_limit*upper_limit) + exp(-1.0 * lower_limit*lower_limit);
		//sum of the first and last elements of the Simpsons equation

		sum_odd = 0;

		for (int i = 1; i <= interval-1; i=i+2)
		{
			//prograded s value
			s = lower_limit+i*h;
			sum_odd = sum_odd + 4*exp(-1*s*s);
		}

		sum_even=0;
		for (int i = 2; i <= interval-2; i=i+2)
		{
			s = lower_limit+i*h;
			sum_even = sum_even + 2*exp(-1*s*s);
		}

		sum = ((2/sqrt(M_PI)) * (sum_f_l + sum_odd + sum_even)* h/3);

		diff = sum-sum_prev;
		check= fabs(diff);
		eps = 1e-9;
		

		if (check < eps)
		{
			return sum;
			keep_going = 0;
		}

		interval = interval*2;
		sum_prev = sum;

	}
}