This program counts words and characters in the whole program.
It does not accept words longer than 20 characters 
and does not accept double space
The program is mace using C and it has two lines in C++, the ones for pausing the screen

#include <stdio.h>
#include <stdlib.h>
#include "iostream"

int nw; // global variable so it can be called in main.. the variable gives number of words

int countCharAndWords(int nc); // this function conts characters and words in the whole program, counts number of characters in the largest word, and returns number of characters in the whole program

int main()
{
	int a;		// variables for calling the function, the parameter variable must be initialized so you can use it
	int b = 0;

	printf("Type something to get number of words and characters typed\n");	// ask the user to enter something

	a = countCharAndWords(b);		// call the function
	
	printf("You typed %i characters and %i words\n", a, nw);	//print on screen
	
	system("pause"); // pause, to see the screen
	return 0;
}

int countCharAndWords(int nc) // funtion for counting number of words and characters
{
	int c;					// variable assigned to getchar()
	int max = 0;			// variable for counting characters to determine if its a real word (it works only if you type words with more than 20 characters)
	int count = 0;			// variable for counting characters in the current word
	nw = 1;		// word counter.. starts from 1 cause when you hit enter to show you results it wont count the last word
	nc = 0;		// character counter in total (in all words)

	while ((c = getchar()) != '\n')		// while the user enters characters and it does not hit enter
	{
		for (int i = 0; i <= max; i++)		// count the characaters in the largest word... that of course is max
		{
			if (i >= 20)			// if max is smaller than 20 characters
			{
				printf("Come on man, that's not even a word. Be Serious!\n");		// print on screen
				system("pause");													// pause to see the screen
				exit(0);															// exit program
			}
		}

		if (c == ' ' || c == '\t')		// if the characters are space or tab
		{
			nw++;			// add 1 in the word counter
			count = 0;				// restart the characters counter so it can start from 0 when new word is started
		}

		if (c == ' ' && (c = getchar() == ' '))		// if the user hit space two times in a row
		{
			printf("Hay, watch your fingers, you typed space more than once continuously!\n");	// print on screen
			system("pause");			// pause to see the screen
			exit(0);				// exit program
		}

		if (c != ' ' && c != '\t')		// if the character is not space and is not tab
		{
			nc++;			// add 1 in the characters counter for total
			count++;		// add 1 in the current word counter 
			if (max < count)		// if max is smaller than the current character counter
			{
				max = count;		// max is becoming as the size of the bigest word so far
			}
		}
	}
	return nc;			// the function returns number of characters in the whole program (in total)
}
