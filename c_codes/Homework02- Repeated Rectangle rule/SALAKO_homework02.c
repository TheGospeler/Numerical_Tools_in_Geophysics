#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(argc, argv)
    int argc;
    char **argv;
{

double x;
double trapezoid();
double rectangle();
int number_of_intervals;
double answer;
double error;
double error_percentage;

// the following variables are fixed for this problem
double upper_limit=1.0;
double lower_limit=0.0;

double real_value= 15.0/16.0; // real answer (from analytical portion). 
                              // This is used for error calculation.


// The following 7 lines reads the number of intervals from the command line
// and prints that information to screen.  
   if (argc<2) 
   {
      fprintf(stdout,"You forgot to enter the number of intervals\n");
      exit(10);
   }
   sscanf(argv[1],"%d",&number_of_intervals);
   fprintf(stdout,"\nYou have chosen to break the function into %d intervals\n\n",number_of_intervals);


// Compute the integral using the rectangle rule   
   answer = rectangle(number_of_intervals, upper_limit, lower_limit);
   error = fabs(answer - real_value);  
   error_percentage = error/real_value*100.0;
   fprintf(stdout,"Rectangle Rule (n=%d):  Answer:  %.5f (Error %.4f%%)\n", number_of_intervals, answer,error_percentage); 
  
// Compute the integral using the trapezoid rule   

   answer = trapezoid(number_of_intervals, upper_limit, lower_limit);
   error = fabs(answer - real_value);  
   error_percentage = error/real_value*100.0;
   fprintf(stdout,"Trapezoid Rule (n=%d):  Answer:  %.5f (Error %.4f%%)\n", number_of_intervals, answer,error_percentage); 


return 0;
}

// RECTANGLE RULE
// This function will compute the integral using the rectangle rule.

double rectangle(number_of_intervals, upper_limit, lower_limit)
       int number_of_intervals;
       double upper_limit;
       double lower_limit;
{
double value;
double function();
double sum;
double x;
double h;
int integration_point;
int number_of_integration_points;

//in the rectangle rule, the number of integration points is equal to the number of intervals

     number_of_integration_points = number_of_intervals;

     // h is the spacing between the integration points.
     h = (upper_limit - lower_limit) / (number_of_intervals*1.0);

     // Here, we will loop through each integration point, adding to the sum at each point.
     sum = 0.0;
     for (integration_point = 1; integration_point <= number_of_integration_points; integration_point++)
     {
         // determine the x value at this particular integration point
         x = lower_limit+h*(integration_point-1);
    
         // add the function value at this x to the sum
         sum = sum + function(x);
     }

     // The rectangle rule says to multiply the value of h by the sum.

     value = h*sum;   

     // This value is our answer, and it will be returned out of this function.  
return value;
}


// TRAPEZOID
// This function will compute the integral using the trapezoid rule.
double trapezoid(number_of_intervals, upper_limit, lower_limit)
       int number_of_intervals;
       double upper_limit;
       double lower_limit;
{

double function();
double value;
double sum;
double x;
double h;
int integration_point;
int number_of_integration_points;
double trap_sum;

// In the trapezoid rule, the number of integration points is equal to the number of intervals,
// But, the summation begins from element 2.

number_of_integration_points = number_of_intervals;

     // h is the spacing between the integration points.
     h = (upper_limit - lower_limit) / (number_of_intervals*1.0);

     // Here, we will loop through each integration point starting from the second element, adding to the sum at each point.
     sum = 0.0;
     for (integration_point = 2; integration_point <= number_of_integration_points; integration_point++)
     {
         // determine the x value at this particular integration point
         x = lower_limit+h*(integration_point-1);

         // add the function value at this x to the sum
         sum = sum + function(x);
     }

     // The trapezoid rule says to take the sum of the global upper_limit and lower_limit and get the mid-point before adding 
     // to the sum.

     trap_sum = 0.5*(function(lower_limit) + function(upper_limit)) + sum;

     value = h*trap_sum;

     // The new value obtained is our trapezoid solution, and it will be returned out of this function.


return value;
}

// FUNCTION
// This is the funtion that you will be integrating.
double function(x)
       double x;
{
double value;

    value = pow(x,3.0)*pow((1+pow(x,4.0)),3.0);


return value;
}





