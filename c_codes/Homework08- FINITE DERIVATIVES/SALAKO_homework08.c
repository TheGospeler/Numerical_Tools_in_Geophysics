#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(string_value, string_array)
int string_value;
char **string_array;
{
	if (string_value < 2)
	{
		fprintf(stdout, "You forgot to enter the method you wish to use!\n");
		fprintf(stdout, "Enter 1 to use Jacobi methods or 2 to use Gauss-Seidel's method\n");
		exit(10);
	}

	int method;
	sscanf(string_array[1],"%d", &method);
	
	int keep_going = 1;
	double F0_prev = 0.0, F_prev=0.5, F10_prev=0.5;

	
	// Creating Array for X and storing the values...
	double X[10+1];
	double val = 0.0; //value to be stored and incremented!
	for (int i = 0; i <= 10; ++i)
	{
			
		X[i] = val;
		val = val + 0.1;
	}

	// The interval between each nodes....

	int iteration_number = 0;
	double a, b, dx = 0.1;

	a = (-1/pow(dx, 2));
	b = ((2*a) - 4);


	if (method == 1)
	{
		fprintf(stdout, "Solver is Jacobi\n");
	
		double F_array_jacob[10+1][2+1]; //holds the old and new function values

		
		// DEFINING AND DECLARING ARRAYS....

		// store up the boundary values F0 and F10
		F_array_jacob[0][1] = 0.0;
		F_array_jacob[10][1] = 1.0;

		// The following code fills the first column of the array with the initial value of 0.5
		for (int i = 1; i <= 9; ++i)
		{
			for (int j = 1; j < 2; ++j)
			{
				F_array_jacob[i][j] = F_prev;
			}
		}

		// Now we have our array with two columns for each function, and we can add and edit as we wish
		// We can setup for the functions....

		while(keep_going)
		{
			for (int i = 1; i <= 9; ++i)
			{
				F_array_jacob[i][2] = (a*(F_array_jacob[i-1][1] + F_array_jacob[i+1][1]) + 3*X[i])/ b; 

			}
			
			if ((fabs(F_array_jacob[1][2] - F_array_jacob[1][1]) < 0.00001)&&(fabs(F_array_jacob[2][2] - F_array_jacob[2][1]) < 0.00001)&&
				(fabs(F_array_jacob[3][2] - F_array_jacob[3][1]) < 0.00001)&&(fabs(F_array_jacob[4][2] - F_array_jacob[4][1]) < 0.00001)&&
				(fabs(F_array_jacob[5][2] - F_array_jacob[5][1]) < 0.00001)&&(fabs(F_array_jacob[6][2] - F_array_jacob[6][1]) < 0.00001)&&
				(fabs(F_array_jacob[7][2] - F_array_jacob[7][1]) < 0.00001)&&(fabs(F_array_jacob[8][2] - F_array_jacob[8][1]) < 0.00001)&&
				(fabs(F_array_jacob[9][2] - F_array_jacob[9][1]) < 0.00001))
			{
				keep_going = 0;
			}

			// replace the previous value with the current value
			for (int i = 1; i <= 9; ++i)
			{
				F_array_jacob[i][1] = F_array_jacob[i][2];
			}
			
			iteration_number = iteration_number + 1;
		}

		fprintf(stdout, "Converged: %d iterations\n\n", iteration_number);

		//print the final values...
		for (int i = 0; i <= 10; ++i)
		{
			fprintf(stdout, "X: %.2f F: %.3f\n", X[i], F_array_jacob[i][1]);
		}

	}


	else if (method == 2)
	{
		fprintf(stdout, "Solver is Gauss-Seidel\n");
	
		
		double F_array_GS[10+1][2+1]; //holds the old and new function values

		
		// DEFINING AND DECLARING ARRAYS....

		// store up the boundary values F0 and F10
		F_array_GS[0][1] = 0.0;
		F_array_GS[10][1] = 1.0;

		// The following code fills the first column of the array with the initial value of 0.5
		for (int i = 1; i <= 9; ++i)
		{
			for (int j = 1; j < 2; ++j)
			{
				F_array_GS[i][j] = F_prev;
			}
		}

		// Now we have our array with two columns for each function, and we can add and edit as we wish
		// We can setup for the functions....

		while(keep_going)
		{
			for (int i = 1; i <= 9; ++i)
			{
				F_array_GS[i][2] = (a*(F_array_GS[i-1][2] + F_array_GS[i+1][1]) + 3*X[i])/ b; 

			}
			
			if ((fabs(F_array_GS[1][2] - F_array_GS[1][1]) < 0.00001)&&(fabs(F_array_GS[2][2] - F_array_GS[2][1]) < 0.00001)&&
				(fabs(F_array_GS[3][2] - F_array_GS[3][1]) < 0.00001)&&(fabs(F_array_GS[4][2] - F_array_GS[4][1]) < 0.00001)&&
				(fabs(F_array_GS[5][2] - F_array_GS[5][1]) < 0.00001)&&(fabs(F_array_GS[6][2] - F_array_GS[6][1]) < 0.00001)&&
				(fabs(F_array_GS[7][2] - F_array_GS[7][1]) < 0.00001)&&(fabs(F_array_GS[8][2] - F_array_GS[8][1]) < 0.00001)&&
				(fabs(F_array_GS[9][2] - F_array_GS[9][1]) < 0.00001))
			{
				keep_going = 0;
			}

			// replace the previous value with the current value
			for (int i = 1; i <= 9; ++i)
			{
				F_array_GS[i][1] = F_array_GS[i][2];
			}
			
			iteration_number = iteration_number + 1;
		}

		fprintf(stdout, "Converged: %d iterations\n\n", iteration_number);

		//print the final values...
		for (int i = 0; i <= 10; ++i)
		{
			fprintf(stdout, "X: %.2f F: %.3f\n", X[i], F_array_GS[i][1]);
		}


	}
	else
	{
		fprintf(stdout, "Error🙄, I will be praying for you! exiting....\n");
		exit(10);
	}
	return 0;
}
