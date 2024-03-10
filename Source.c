#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define rows 20
#define characters 129
#define words 6

int wordCounter = 0;

char* userArray[rows][characters];

int main()
{
	input();

	output();

	consonantCounter();

	return 0;
}

int input(void) // rows <= 20; letters <= 128; 2 <=  words <= 20; enter - next string; 'esc' - end of input;
{
	char Letters[] = "wWeErRtTyYuUiIoOpPaAsSdDfFgGhHjJkKlLzZxXcCvVbBnNmM";
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

					if (strchr(Letters, userArray[i][j - 1]) != NULL
						&& userArray[i][j] == ' ') 
					{
						wordCounter += 1;

						if (wordCounter == words)
						{
							printf("\n");
							break;
						}
					}
				}
				if (j > 2)
				{
					if (strchr(Letters, userArray[i][j - 2]) != NULL
						&& strchr(Letters, userArray[i][j - 1]) == NULL
						&& userArray[i][j] == ' ')
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
			else if (character == 13 && wordCounter >= 2)//enter pressed
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

int output(void)
{
	printf("\n\n");
	for (int i = 0; i < rows; i++)
	{
		if (userArray[i][0] != '\0')
		{
			for (int j = 0; j < characters; j++)
			{
				printf("%c", userArray[i][j]);
			}
		}
		else
		{
			printf("\n");
			return 0;
		}

		printf("\n");
	}
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
				printf("%c", userArray[i][c]);
			}
		}
		else
		{
			printf("\n");
			return 0;
		}
	}
}
