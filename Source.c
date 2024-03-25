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
			else if (character == 27 && wordCounter >= 2) //нажат esc и введено хотя бы 2 слова
			{
				return 0;
			}
			else if (character == 13 && wordCounter >= 2) //нажат enter и введено хотя бы 2 слова
			{
				printf("\n");
				break;
			}
			else
			{
				//не введено хотя бы 2 слова
			}
		} 
	}
}

int isWord(int i, int j) //если в последовательности сиволов есть хотя бы одна буква до первого пробела, то это слово
{
	int thereIsALetter = 0;

	for (j; j >= 0; j--)
	{
		if (userArray[i][j] != ' ')
		{
			for (int k = 0; k < strlen(Letters); k++)
			{
				if (userArray[i][j] == Letters[k])
				{
					thereIsALetter = 1;
				}
			}
		}
		else
		{
			break;
		}
	}      

	if (thereIsALetter != 0)
	{
		return 0; //is a word
	}
	else
	{
		return 1; //not a word
	}
}

int output(void)
{
	printf("\n\nText:\n");
	for (int i = 0; i < rows; i++)
	{
		if (userArray[i][0] != '\0') //если первый символ строки не равен \0, т.е. строка не пуста
		{
			for (int j = 0; j < characters; j++) //то выводим все символы этой строки
			{
				printf("%c", userArray[i][j]);
			}
		}
		else //если строка все-таки пуста, то переходим к следующей строке
		{
			break;
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

	printf("\nModified text:\n");

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
			printf("%s", ModString);

			for (int c = 0; c < characters; c++)
			{
				printf("%c", userArray[i][c]);
			}
		}
		else
		{
			break;
		}
		printf("\n");
	}
}
