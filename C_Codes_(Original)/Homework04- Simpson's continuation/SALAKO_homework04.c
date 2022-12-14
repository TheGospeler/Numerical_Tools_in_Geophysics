#include<stdio.h>
#include<stdlib.h>
#include<math.h>


// Include the text file "function.h" which contains the function that 
// we will integrate.  

#include "function.h"


int main(number_of_strings, string_array)
    int number_of_strings;
    char **string_array;
{

// Declaration of variables
double upper_limit, lower_limit;

// START OF Code written by Allen to read lower and upper limits from the command line.

   if (number_of_strings<3)
   {
      fprintf(stdout,"You forgot to enter numbers on the command line:  lower_bound, upper_bound\n");
      exit(10);
   }
   sscanf(string_array[1],"%lf", &lower_limit);
   fprintf(stdout,"The lower bound of the integral is: %f\n", lower_limit);
   sscanf(string_array[2],"%lf", &upper_limit);
   fprintf(stdout,"The upper bound of the integral is: %f\n", upper_limit);
   // make sure upper bound in greater than lower bound
   if (upper_limit <= lower_limit)
   {
       fprintf(stdout,"ERROR-your upper bound (%f) is less than or equal to your lower bound (%f)\n", upper_limit, lower_limit);
       exit(10);
   }
// END OF Code written by Allen to read lower and upper limits from the command line.


   double simpson(); 
   simpson(upper_limit, lower_limit);



return 0;
}


double simpson(upper_limit, lower_limit)
double upper_limit, lower_limit;

{
   int interval= 2;
   int keep_going=1;
   double function();
   double sum_prev= 0.0; // variable to store the previous iterated value

   while(keep_going)
   {
      double h, sum_f_l, sum_odd, sum_even, sum, check, eps, diff;


      h = (upper_limit - lower_limit) /  (interval *1.0);
      // the distance between each nodes

      sum_f_l = function(upper_limit) + function(lower_limit);
      //sum of the first and last elements of the Simpsons equation
      sum_odd = 0;

      //sums up all the odd elements
      for (int i = 1; i <= interval-1; i=i+2)
      {
         sum_odd = sum_odd + 4*function(lower_limit+i*h);
      }

      // sums up all the even elements.
      sum_even=0;
      for (int i = 2; i <= interval-2; i=i+2)
      {
         sum_even = sum_even + 2*function(lower_limit+i*h);
      }

      //sums up the entire sums
      sum = (sum_f_l + sum_odd + sum_even)* h/3;

      diff = sum-sum_prev;
      check= fabs(diff); // returns the absolute value
      eps = 1e-7;
      

      if (check < eps)
      {
         keep_going = 0;
      }

      fprintf(stdout, "number_of_intervals: %d result: %.8f\n", interval, sum);

      interval = interval*2; // increase the interval by 2 per iteration.
      sum_prev = sum;

   }

   return 0;
}

