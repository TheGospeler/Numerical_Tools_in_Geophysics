#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(number_of_strings, string_array)
int number_of_strings;
char**string_array;
{

	// Declaring essential variables.
	FILE*fpin;
	char temp_string[200];
	int number_of_xnodes;
	int number_of_ynodes;
	double value;
	double h, k;


	// A fail-safe function that allows the code to warn the user if they forget to input the files needed
	if(number_of_strings<=1)
	{
		fprintf(stdout, "Error: forgot to include input file on command line\n");
		exit(10);
	}

	// Read (Display) the name of the file inputed from the command line.
	fprintf(stdout, "Input file: %s\n", string_array[1]);

	// Opening the file
	fpin = fopen(string_array[1], "r");

	// Confirm if the file opens if not Exit.
	if (fpin == NULL)
	{
		fprintf(stdout, "Error: cannot open input file %s\n", string_array[1]);
	}

	//Read the first line of the file to get the number of nodes in the x and y direction and intervals btwn x and y respectively
	fgets(temp_string, 200, fpin);

	// parsing the info into the variables to keep
	sscanf(temp_string, "%d %d %lf %lf", &number_of_xnodes, &number_of_ynodes, &h, &k);

	// prints out the number of nodes we have in the x and y direction respectively.
	fprintf(stdout, "Number of nodes in x-direction: %d Size of h: %f\n", number_of_xnodes, h);
	fprintf(stdout, "Number of nodes in y-direction: %d Size of k: %f\n", number_of_ynodes, k);

	// We create an array with nth dimension based on the nodes of X and Y
	double my_array[number_of_xnodes+1][number_of_ynodes+1];

	double temp_xnodes;
	double temp_ynodes;

	// The loop below stores data into the array (my_array) from the southwestern angle towards the east of the inputed data
	// based on the size of the size of the row and column inputed.

	for (int j = 1; j <= number_of_ynodes; ++j)
	{
		for (int i = 1; i <= number_of_xnodes; ++i)
		{
			fgets(temp_string, 200, fpin);

			// parsing the file into the position of the array
			sscanf(temp_string, "%lf %lf %lf", &temp_xnodes, &temp_ynodes, &my_array[i][j]);
		}
	}


	// try to sum up the group elements based on the double simpson's integral rule
	double grp1, grp2, grp3, grp4, grp5, grp6, grp7, grp8, grp9;
	double total_erosion_volume;
	double sum;
	int P, Q;
	P = number_of_xnodes;
	Q = number_of_ynodes;

	/*******************GROUP 1**************************/

	grp1 = my_array[1][1] + my_array[P][1] + my_array[1][Q] + my_array[P][Q];
	
	/*******************GROUP 2****************************/

	sum = 0.0;
	for (int j = 2; j <= Q-1; j=j+2)
	{
		sum =sum + 4*(my_array[1][j] + my_array[P][j]);
	}
	grp2 = sum;

	/*******************GROUP 3****************************/

	sum = 0.0;
	for (int j = 3; j <= Q-2; j=j+2)
	{
		sum =sum + 2*(my_array[1][j] + my_array[P][j]);
	}
	grp3 = sum;
	
	/*******************GROUP 4****************************/

	sum = 0.0;
	for (int i = 2; i <= P-1; i=i+2)
	{
		sum =sum + 4*(my_array[i][1] + my_array[i][Q]);
	}
	grp4 = sum;

	/*******************GROUP 5****************************/

	sum = 0.0;
	for (int i = 3; i <= P-2; i=i+2)
	{
		sum =sum + 2*(my_array[i][1] + my_array[i][Q]);
	}
	grp5 = sum;

	/*******************GROUP 6****************************/
	sum = 0.0;
	for (int j = 3; j <= Q-2; j=j+2)
	{
		for (int i = 2; i <= P-1; i=i+2)
		{
			sum = sum + 8*(my_array[i][j]);
		}
	}
	grp6 = sum;

	/*******************GROUP 7****************************/
	sum = 0.0;
	for (int j = 2; j <= Q-1; j=j+2)
	{
		for (int i = 3; i <= P-2; i=i+2)
		{
			sum = sum + 8*(my_array[i][j]);
		}
	}
	grp7 = sum;

	/*******************GROUP 8****************************/
	sum = 0.0;
	for (int j = 2; j <= Q-1; j=j+2)
	{
		for (int i = 2; i <= P-1; i=i+2)
		{
			sum = sum + 16*(my_array[i][j]);
		}
	}
	grp8 = sum;

	/*******************GROUP 9****************************/
	sum = 0.0;
	for (int j = 3; j <= Q-2; j=j+2)
	{
		for (int i = 3; i <= P-2; i=i+2)
		{
			sum = sum + 4*(my_array[i][j]);
		}
	}
	grp9 = sum;

	/*******************END OF GROUP****************************/

	total_erosion_volume = (h*k/9)*(grp1 + grp2 + grp3 + grp4 + grp5 + grp6 + grp7 + grp8 + grp9);

	printf("Integral Value: %.3e\n", total_erosion_volume);

	return 0;
}