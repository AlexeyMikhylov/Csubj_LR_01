#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define rows 5
#define characters 129
#define words 5

char Letters[] = "QqwWeErRtTyYuUiIoOpPaAsSdDfFgGhHjJkKlLzZxXcCvVbBnNmMm";
char* userArray[rows][characters];
int wordCounter = 0;

int main()
{
	input();

	output();

	consonantCounter();

	return 0;
}

int input(void) // rows <= 20; letters <= 128; 2 <=  words <= 20; enter -> next string; 'esc' -> end of input;
{
	char character;

	for (int i = 0; i < rows; i++)
	{
		wordCounter = 0;

		for (int j = 0; j < characters; j++)
		{
			character = getch();

			if (character != 13 && character != 27)
			{
				userArray[i][j] = character;
				fprintf(stdout, "%c", character);

				if (j != 0)
				{
					if (isWord(i, j-1) == 0 && userArray[i][j] == ' ')
					{
						wordCounter += 1;

						if (wordCounter == words)
						{
							printf("\n");
							break;
						}
					}
				}
			}
			else if (character == 27 && wordCounter >= 2) //esc pressed
			{
				return 0;
			}
			else if (character == 13 && wordCounter >= 2) //enter pressed
			{
				printf("\n");
				break;
			}
			else
			{

			}
		} 
	}
}

int isWord(int i, int j) //if there is at least one letter between spaces, it is a word
{
	for (j; j >= 0; j--)
	{
		/*if (userArray[i][j] == ' ')
		{
			return 1; 
		}
		else
		{
			if (strchr(Letters, userArray[i][j]) != NULL)
			{
				return 0;
			}
		}*/

		if (strchr(Letters, userArray[i][j]) != NULL)
		{
			return 0;
		}
		else if (userArray[i][j] == ' ')
		{
			break; return 1;
		}
		else
		{

		}

	}
}

int output(void)
{
	printf("\n\n");
	for (int i = 0; i < rows; i++)
	{
		/*if (userArray[i][0] != '\0')
		{
			for (int j = 0; j < characters; j++)
			{
				printf("%c", userArray[i][j]);
			}
		}*/
		
		for (int j = 0; j < characters; j++)
		{
			if (userArray[i][j] != '\0')
			{
				printf("%c", userArray[i][j]);
			}
			else
			{
				break;
			}
		}
	}

	printf("\n");
}

int consonantCounter(void)
{
	char MyStr[100], ModString[250];
	char EnDisowels[] = "qwrtpsdfghjklzxcvbnmQWRTPSDFGHJKLZXCVBNM";
	int CountDisowels = 0; 

	int i = 0;

	printf("\n");
	for (i; i < rows; i++)
	{
		CountDisowels = 0;

		for (int j = 0; j < characters; j++)
		{
			for (int k = 0; k < strlen(EnDisowels); k++)
			{
				if (userArray[i][j] == EnDisowels[k])
				{
					CountDisowels += 1;
				}
			}
		}

		sprintf(ModString, "%d %c", CountDisowels, ' '); 

		if (userArray[i][0] != '\0')
		{
			printf("\n");
			printf("%s", ModString);

			for (int c = 0; c < characters; c++)
			{
				if (userArray[i][c] != '\0')
				{
					printf("%c", userArray[i][c]);
				}
				else
				{
					break;
				}
			}
		}
	}
	printf("\n");
}
