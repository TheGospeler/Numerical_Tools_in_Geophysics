#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

	int print_runge=1;
	
	double RkSecond(); //The Range-Kutta function.
	double rk_previous_func = 0.0;
	double rk_current_func;
	double error_check;
	double eps = 1e-5;

	// Values provided...
	int number_of_steps = 1;
	double upper_limit = 10.0;
	double lower_limit = 0.0;

	// Print Runge-Kutta Method output....	
	while(print_runge)
	{
		rk_current_func = RkSecond(number_of_steps, upper_limit, lower_limit);
					
		error_check = fabs(rk_current_func - rk_previous_func);
		
		// chcecks to see if the disparity matches the limit but printing.
		if (error_check < eps)
		{
			print_runge = 0;

		}
		fprintf(stdout, "Runge-Kutta(NumberOfSteps: %d) f(x=5.0) = %.5f\n", number_of_steps, rk_current_func);

		number_of_steps = number_of_steps*2;
		rk_previous_func = rk_current_func;

	}
	
return 0;
}

// function equation:
double S(x, f, g)
double x; // the value of x
double f; // the function of x
double g; // The first derivative of x
{
	double dx2; // The second derivative...
	dx2 = 24*cos(4*x) - 16*f;

	return dx2;
}




//The Runge-Kutta Method embraces the Gauss-Legendre n=1 Method.
	double RkSecond(number_of_steps, upper_limit, lower_limit)
	int number_of_steps;
	double upper_limit;
	double lower_limit;
	
	{
		// Create an output file
		FILE*fpin;
		fpin = fopen("SALAKO.HW07B.output", "w");

		// Declaration of germane variables.
		double S();
		double x, xi, h;
		int step_point;
		int number_of_step_points;

		
	    // h is the spacing between the integration points.
	    h = (upper_limit - lower_limit) / (number_of_steps*1.0);

	    //The initial condition, which is the boundary condition was given (initial_f).
		double initial_f = 0.0, initial_g = 0.0;
		double current_f, current_g;
		double runge_kutta, mid;
		double Ko, K1, K2, K3;
		double Lo, L1, L2, L3;

		number_of_step_points = number_of_steps;
	 
		// loop through the number of steps and increment
	    for (step_point = 1; step_point <= number_of_step_points; step_point++)
	    {

	    	// determine the x value at this particular prograded step_point
	         x  = lower_limit+h*(step_point-1);
	         xi = lower_limit+h*(step_point);
	         mid = h/2.0;

	         // Initial condtions
	         Lo = h*S(x, initial_f, initial_g);
		    Ko = h*initial_g;

	        // A more structured code is by breaking the code
	         L1 = h*S(x+mid, initial_f+Ko/2.0, initial_g+Lo/2.0);
	         K1= h*(initial_g + Lo/2.0);

	         L2 = h*S(x+mid, initial_f+K1/2.0, initial_g+L1/2.0);
	         K2 = h*(initial_g +L1/2.0);

	         L3 = h*S(xi, initial_f+K2, initial_g+L2);
	         K3 = h*(initial_g + L2);

	         current_g = initial_g + (Lo + 2*L1 +2*L2 + L3)/6.0;
	         current_f = initial_f + (Ko + 2*K1 +2*K2 + K3)/6.0;

	         // Write the input of f and g into file
	         fprintf(fpin, "%f %f %f\n", x, current_f, current_g);

	         // re-initialize f and g for the next looping.
	         initial_f = current_f;
	         initial_g = current_g;

	    }
	    runge_kutta = current_f;

	    fclose(fpin);

	    return runge_kutta;

	}
	
