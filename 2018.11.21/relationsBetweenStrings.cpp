#include <iostream>

using namespace std;

bool ifStringsAreEqual(char[], char[]);
int inputDimensionOfString();
void inputString(char*, int);
char orderBetweenStrings(int, int);

int main()
{
	int n = inputDimensionOfString();
	int m = inputDimensionOfString();

	char string1[100], string2[100];

	cout << "Enter first string: ";
	inputString(string1, n);

	cout << "Enter second string: ";
	inputString(string2, m);

	if (ifStringsAreEqual(string1, string2))
		cout << "Strings are equal" << endl;
	else cout << "Strings aren't equal" << endl;

	cout << "string1 " << orderBetweenStrings(n, m) << " string2" << endl;

	system("pause");
	return 0;
}

bool ifStringsAreEqual(char string1[], char string2[])
{
	int n = 0;
	for (int i = 0; i < 100; i++)
	{
		if (string1[i] != string2[i])
			return false;
		else n++;
	}
	if (n == 100)
		return true;
}

char orderBetweenStrings(int n, int m)
{
	if (n == m)
	{
		return '=';
	}
	else 
		if (n < m)
		{
			return '<';
		}
		else
			if (n > m)
			{
				return '>';
			}
	return -1;
}

int inputDimensionOfString()
{
	int dimension;
	cout << "Enter the dimension of string: ";
	cin >> dimension;
	return dimension;
}

void inputString(char* string, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> string[i];
	}
}