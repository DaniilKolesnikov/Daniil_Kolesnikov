#include <iostream>

using namespace std;

int inputDimensionOfString();
void inputString(char*, int);
int indexOfSubstring(char*, int, char*, int);

int main()
{
	int n = inputDimensionOfString();
	int m = inputDimensionOfString();
	char string[100], substring[100];

	cout << "Enter string: ";
	inputString(string, n);

	cout << "Enter substring: ";
	inputString(substring, m);

	cout << "index of substring: " << indexOfSubstring(string, n, substring, m) << endl;

	system("pause");
	return 0;
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

int indexOfSubstring(char* string, int n, char* substring, int m)
{
	if (m > n)
	{
		cout << "invalid data!";
		return -1;
	}
	int count = 0, index = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (substring[j] == string[i + count])
			{
				index = i;
				count++;
				if (j == m - 1)
				{
					return index;
				}
				else
				{
					continue;
				}
			}
			else
			{
				index = -1;
				count = 0;
				break;
			}
		}
	}
	return -1;
}