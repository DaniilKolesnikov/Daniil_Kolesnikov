#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

typedef char*(*codeString)(char);
typedef char*(*Code)(char*, int, codeString);

const int N = 256;

char* codingWords(char*, int, codeString);
char* codingString(char);
char* codingString2(char);
char* changeWord(char*, int, Code, codeString);

int main()
{
	//char string[N];
	//cout << "Enter the string:" << endl;
	//cin >> string[N];

	char string[N] = "The Centre of the International Communication";
	int lenCodingWords = 3;


	cout << changeWord(string, lenCodingWords, codingWords, codingString) << endl;

	cout << changeWord(string, lenCodingWords, codingWords, codingString2) << endl;

	system("pause");

	return 0;
}

char* changeWord(char* source, int lengthWords, Code code, codeString codingString)
{
	const char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char* word = strpbrk(source, symbols);
	char* result = new char[N] {0};

	while (word)
	{
		int length = strspn(word, symbols);

		if (lengthWords == length)
		{
			char* n = code(word, length, codingString);
			strcat(result, n);
			word += length;
			word = strpbrk(word, symbols);
		}
		else
		{
			strncat(result, word, length + 1);
			word += length;
			word = strpbrk(word, symbols);
		}
	}

	delete[] word;

	return result;
}

char* codingString(char string)
{
	const char* symbols = "(ZYXVWUTSRQPONMLKJIHGFEDCBA)";

	char* code = new char[5]{ 0 };

	for (int j = 0; j < strlen(symbols) + 1; j++)
	{
		if (toupper(string) == symbols[j])
		{
			code[0] = symbols[0];
			if (j < 10)
			{
				code[1] = j + '0';
				code[2] = symbols[27];
			}
			else
			{
				code[1] = j / 10 + '0';
				code[2] = j % 10 + '0';
				code[3] = symbols[27];
			}

		}
	}

	return code;
}

char* codingWords(char* word, int length, codeString codingString)
{
	char* result = new char[N] {0};

	for (int i = 0; i < length; i++)
	{
		strcat(result, codingString(word[i]));
	}

	strcat(result, " ");

	return result;
}

char* codingString2(char string)
{
	const char* symbols = "(ZYXVWUTSRQPONMLKJIHGFEDCBA)";

	char* code = new char[5]{ 0 };

	for (int j = 0; j < strlen(symbols) + 1; j++)
	{
		if (toupper(string) == symbols[j])
		{
			code[0] = symbols[27 - j];
		}
	}

	return code;
}