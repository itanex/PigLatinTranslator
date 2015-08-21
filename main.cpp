/*
Bryan Wood
main.cpp

This program opens an input and output file intreractively
	with user. Then uses the data from the input file and
	manipulates it into piglatin and outputs the newly 
	translated text to a new file.

This program assumes that the user will not input any words that
	contains more then 40 to be translated and that the file name 
	will not contain more then 20 characters and no whites spaces.

input, output
*/

#include "lib.h"

void main (void)
{
	ifstream
		input;
	ofstream
		output;


	openfiles (input, output);  // opens file interactively with user
	manipstr (input, output);   // translates input and the outputs to a new file
	closefiles (input, output); // closes the files
 
}
