#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
	// functions that solves ODE using Euler, Modified Euler (Heun's), Midpoint, and Fourth-Order Runge-Kutta Method.
	
	
	int print_euler = 1, print_modeuler = 1, print_midpoint= 1, print_runge=1;
	double euler();
	double modified_euler();
	double midpoint();
	double RK(); 			//The Range-Kutta function.

	// container that stores the previous function value.
	double eur_previous_func = 0.0, modeur_previous_func = 0.0, mid_previous_func = 0.0, rk_previous_func = 0.0; 

	// Essential variables
	double eur_current_func, modeur_current_func, mid_current_func, rk_current_func;
	double error_check;
	double eps = 1e-5;
	
	// Values provided...
	int number_of_steps = 1;
	double upper_limit = 5.0;
	double lower_limit = 2.0;

	// Print Euler output....
	while(print_euler)
	{
		eur_current_func = euler(number_of_steps, upper_limit, lower_limit);
				
		error_check = eur_current_func - eur_previous_func;

		// chcecks to see if the disparity matches the limit but printing.
		if (error_check < eps)
		{
			print_euler = 0;

		}
		fprintf(stdout, "Euler(NumberOfSteps: %d) f(x=5.0) = %.5f\n", number_of_steps, eur_current_func);

		number_of_steps = number_of_steps*2;
		eur_previous_func = eur_current_func;
	}
	number_of_steps = 1; // returning the number_of_step to 1.
	fprintf(stdout, "\n"); // Seperating Space...


	// Print ModifiedEuler output....	
	while(print_modeuler)
	{
		modeur_current_func = modified_euler(number_of_steps, upper_limit, lower_limit);
				
		error_check = modeur_current_func - modeur_previous_func;

		// chcecks to see if the disparity matches the limit but printing.
		if (error_check < eps)
		{
			print_modeuler = 0;

		}
		fprintf(stdout, "ModifiedEuler(NumberOfSteps: %d) f(x=5.0) = %.5f\n", number_of_steps, modeur_current_func);

		number_of_steps = number_of_steps*2;
		modeur_previous_func = modeur_current_func;

	}
	number_of_steps = 1;
	fprintf(stdout, "\n");


	// Print Midpoint output....	
	while(print_midpoint)
	{
		mid_current_func = midpoint(number_of_steps, upper_limit, lower_limit);
				
		error_check = mid_current_func - mid_previous_func;

		// chcecks to see if the disparity matches the limit but printing.
		if (error_check < eps)
		{
			print_midpoint = 0;

		}
		fprintf(stdout, "Midpoint(NumberOfSteps: %d) f(x=5.0) = %.5f\n", number_of_steps, mid_current_func);

		number_of_steps = number_of_steps*2;
		mid_previous_func = mid_current_func;

	}
	number_of_steps = 1;
	fprintf(stdout, "\n");


	// Print Runge-Kutta Method output....	
	while(print_runge)
	{
		rk_current_func = RK(number_of_steps, upper_limit, lower_limit);
				
		error_check = rk_current_func - rk_previous_func;

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



// The Euler's method adopts the modus operandi of the Rectangle rule.

double euler(number_of_steps, upper_limit, lower_limit)
       int number_of_steps;
       double upper_limit;
       double lower_limit;
{
// Declaration of germane variables.
double S();
double x;
double h;
int step_point;
int number_of_step_points;

	//in the rectangle and euler rule, the number of integration points is equal to the number of intervals

	number_of_step_points = number_of_steps;
 
    // h is the spacing between the integration points.
    h = (upper_limit - lower_limit) / (number_of_steps*1.0);

    
    //The initial condition, which is the boundary condition was given (initial_f).
    double initial_f = 2.0, current_f;
    double euler;

    // loop through the number of steps and increment
    for (step_point = 1; step_point <= number_of_step_points; step_point++)
    {

    	// determine the x value at this particular prograded step_point
         x = lower_limit+h*(step_point-1);

        // calculate the current function f(x)
        current_f = initial_f+h*S(x, initial_f);

        // re-initialize f for the next looping.
        initial_f = current_f;

    }
    euler = current_f;
 
	return euler;
}


// The modified Euler (Heun's) Method!
double modified_euler(number_of_steps, upper_limit, lower_limit)
       int number_of_steps;
       double upper_limit;
       double lower_limit;
{
// Declaration of germane variables.
double xo, xi;
double h;
int step_point;
int number_of_step_points;

	number_of_step_points = number_of_steps;
 
    // h is the spacing between the integration points.
    h = (upper_limit - lower_limit) / (number_of_steps*1.0);

    
    //The initial condition, which is the boundary condition was given (initial_f).
    double initial_f = 2.0, current_f;
    double mod_euler, Ko, Ki, initial_k;
    double S();

    // loop through the number of steps and increment
    for (step_point = 1; step_point <= number_of_step_points; step_point++)
    {

    	// determine the xo and xi is used for Ko and Ki respectively
         xo = lower_limit+h*(step_point-1);
         xi = lower_limit+h*(step_point);

        // calculate the current function f(x)
        Ko = h*S(xo, initial_f);

        Ki = h*S(xi, initial_f+Ko);

        current_f = initial_f + 0.5*(Ko + Ki);

        // re-initialize f for the next looping.
        initial_f = current_f;

    }

    mod_euler = current_f;
 
	return mod_euler; 
}


//The midpoint Method embraces the Gauss-Legendre n=1 Method.
double midpoint(number_of_steps, upper_limit, lower_limit)
       int number_of_steps;
       double upper_limit;
       double lower_limit;
{
// Declaration of germane variables.
double S();
double x, h;
int step_point;
int number_of_step_points;

	number_of_step_points = number_of_steps;
 
    // h is the spacing between the integration points.
    h = (upper_limit - lower_limit) / (number_of_steps*1.0);

	//The initial condition, which is the boundary condition was given (initial_f).
	double initial_f = 2.0, current_f;
	double midpoint, mid;
	double Ko, Ki;

	// loop through the number of steps and increment
    for (step_point = 1; step_point <= number_of_step_points; step_point++)
    {

    	// determine the x value at this particular prograded step_point
         x = lower_limit+h*(step_point-1);
         mid = h/2;

        // calculate the current function f(x)
        // The following code calculates the midpoint rule on a straight line...

        /*current_f = initial_f + h*S(x+mid, (initial_f + mid*S(x, initial_f)));*/

        // A more structured code is by breaking the code
         Ko = h*S(x, initial_f);
         Ki = h*S((x+mid), (initial_f + Ko/2));

         current_f = initial_f + Ki;
        // re-initialize f for the next looping.
        initial_f = current_f;

    }
    midpoint = current_f;
    return midpoint;
}


//The Runge-Kutta Method embraces the Gauss-Legendre n=1 Method.
double RK(number_of_steps, upper_limit, lower_limit)
       int number_of_steps;
       double upper_limit;
       double lower_limit;
{
// Declaration of germane variables.
double S();
double x, h;
int step_point;
int number_of_step_points;

	number_of_step_points = number_of_steps;
 
    // h is the spacing between the integration points.
    h = (upper_limit - lower_limit) / (number_of_steps*1.0);

    //The initial condition, which is the boundary condition was given (initial_f).
	double initial_f = 2.0, current_f;
	double runge_kutta, mid;
	double Ko, K1, K2, K3;

	// loop through the number of steps and increment
    for (step_point = 1; step_point <= number_of_step_points; step_point++)
    {

    	// determine the x value at this particular prograded step_point
         x = lower_limit+h*(step_point-1);
         mid = h/2;

        // calculate the current function f(x), It has a similitude of Simpson's

        // A more structured code is by breaking the code
         Ko = h*S(x, initial_f);
         K1 = h*S((x+mid), initial_f + Ko/2);
         K2 = h*S((x+mid), initial_f + K1/2);
         K3 = h*S((x+h), initial_f + K2);

         current_f = initial_f + (Ko + 2*K1 +2*K2 + K3)/6;

         // re-initialize f for the next looping.
         initial_f = current_f;

    }
    runge_kutta = current_f;
    return runge_kutta;
}

double S(x, f)
double x, f;
{
	return (x+f)/x;
}