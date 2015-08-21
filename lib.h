/*
Bryan Wood	
lib.h
input, output, word, x, wordlength, linelength
*/

#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*-------------------------------------------------------
opens files to be used as input and output
Receives: input, output
Returns: nothing
---------------------------------------------------------*/
void openfiles (ifstream input, ofstream output);

/*-------------------------------------------------------
closes files used as input and output
Receives: input, output
Returns: nothing
---------------------------------------------------------*/
void closefiles (ifstream input, ofstream output);

/*-------------------------------------------------------
Translates the input file to pig latin using two other functions 
	and then outputs the translated verion into the output file
Receives: input, output
Returns: nothing
---------------------------------------------------------*/
void manipstr (ifstream input, ofstream output);

/*-------------------------------------------------------
Translates the input file to pig latin
Receives: input, output, word, x, wordlength
Returns: word, x, wordlength
---------------------------------------------------------*/
void piglatin (ifstream input, ofstream output, char word[], 
			   int &x, int &wordlength);

/*-------------------------------------------------------
Outputs the translated version to the output file and controls 
	the format of the output.
Receives: output, word, wordlength, linelength
Returns: word, wordlength, linelength
---------------------------------------------------------*/
void manipout (ofstream output, char word[], int &wordlength, 
			   int &linelength);
