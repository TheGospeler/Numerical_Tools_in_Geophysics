#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(number_of_strings, string_array)
int number_of_strings;
char**string_array;
{
	// number_of_strings tells us how many element or items we inputed in the command prompt.

	fprintf(stdout, "There are %d strings on text on the command line\n", number_of_strings);

	// we can print out all the items on the command line by looping through the array.
	// The array starts counting from 0, hence we have to put this into consideration.

	for (int istring = 0; istring <= number_of_strings; ++istring)
	{
		fprintf(stdout, "The %d-th item is %s\n", istring+1, string_array[istring]);
	}

	double function
	return 0;
}