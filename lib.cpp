/*
Bryan Wood
lib.cpp

infile, outfile, input, output, word, x, wordlength, 
	linelength, holder

*/

#include "lib.h"

/*-------------------------------------------------------
opens files to be used as input and output
Receives: input, output
Returns: nothing
---------------------------------------------------------*/
void openfiles (ifstream input, ofstream output)
{
	char
		infile [20],
		outfile [20];

	// opens the file that will be used as the input file
	cout << "Enter the name of input file to be opened: ";
	cin >> infile;

	input.open(infile, ios::nocreate);
	while (input.fail())
	{
		cout << "Could not open " << infile 
			 << " please re-enter the file name: " << endl;
		cin >> infile;
		input.open(infile, ios::nocreate);
		input.clear();
	}

	// opens the file that will be used as the output file
	cout << "Enter the name of output file to be opened: ";
	cin >> outfile;
	output.open(outfile, ios::out);


}//end sub

/*-------------------------------------------------------
closes files used as input and output
Receives: input, output
Returns: nothing
---------------------------------------------------------*/
void closefiles (ifstream input, ofstream output)
{
	input.close ();
	output.close();

}//end sub

/*-------------------------------------------------------
Translates the input file to pig latin using two other functions 
	and then outputs the translated verion into the output file
Receives: input, output
Returns: nothing
---------------------------------------------------------*/
void manipstr (ifstream input, ofstream output)
{
	char word[40];
	int x,   // counter for word
		wordlength, // place holder for the length of the word
		linelength = 0; // place holder for the length of the line

	// loop that manipulates the input file word by word 
	// and then outputs the new word.
	do
	{
		input >> word;

		piglatin (input, output, word, x, wordlength);   // modifies word
		manipout (output, word, wordlength, linelength); // outputs word
	}while (!input.eof());
}//end sub

/*-------------------------------------------------------
Translates the input file to pig latin
Receives: input, output, word, x, wordlength
Returns: word, x, wordlength
---------------------------------------------------------*/
void piglatin (ifstream input, ofstream output, char word[], 
			   int &x, int &wordlength)
{
	char holder;
	wordlength = strlen (word);
	holder= word [0];
	
	//determines if the word begins with a vowel or constinant
	if (word[0] == 'a' || word[0] == 'A' || 
		word[0] == 'e' || word[0] == 'E' ||	
		word[0] == 'i' || word[0] == 'I' || 
		word[0] == 'o' || word[0] == 'O' || 
		word[0] == 'u' || word[0] == 'U' )
	{
		// configures the word if vowel begins word
		word[wordlength] = 'y';		// adds y to the end
		word[wordlength+1] = 'a';	// adds a to the end
		word[wordlength+2] = 'y';	// adds y to the end
		word[wordlength+3] = '\0';	// adds null char to the end
	}

	else
	{
		// configures the word if constinant begins word
		for (x = 0; x < wordlength; x++)
		{
			word[x] = word[x+1];
		}
		word[wordlength-1] = holder; // adds first letter to end
		word[wordlength] = 'a';      // adds a to the end
		word[wordlength+1] = 'y';    // adds y to the end
		word[wordlength+2] = '\0';   // adds null char to the end
	}
}//end sub

/*-------------------------------------------------------
Outputs the translated version to the output file and controls 
	the format of the output.
Receives: output, word, wordlength, linelength
Returns: word, wordlength, linelength
---------------------------------------------------------*/
void manipout (ofstream output, char word[], int &wordlength, 
			   int &linelength)
{
	wordlength = strlen (word); // finds and holds the length of the word
	linelength += wordlength;	// increments linelength by wordlength
	
	if (linelength > 70) // creates a standard width of 70 and
	{					 // resets linelength if it creates a new line
		output << endl;
		linelength = wordlength;
	}

	output << word << " "; //outputs the manipulated word
}//end sub