#include <iostream>

using namespace std;

int nextSmallerThan(int);
void nextSmallerThanTests();
void swap(int& x, int& y);
void numberToArray(int, int[], int);
int arrayToNumber(int[], int);


int main()
{
	int number;
	//cout << "enter positive number: ";
	//cin >> number;
	//cout << endl;

	//cout << nextSmallerThan(number) << endl;

	nextSmallerThanTests();
	system("pause");
}

int nextSmallerThan(int number)
{
	int numberArray[10] = { 0 }, i = 0, number2 = 0;
	int startNumber = number;

	while (number > 0)
	{
		numberArray[i] = number % 10;
		number /= 10;
		i++;
	}

	for (int j = 0; j < i; j++)
	{
		swap(numberArray[j], numberArray[j + 1]);

		if ((j + 1) >= i )
			return -1;

		number2 = arrayToNumber(numberArray, i);

		int l = 0, extraArray[10] = { 0 }, number2extra = number2;
		while (number2extra > 0)
		{
			extraArray[l] = number2extra % 10;
			number2extra /= 10;
			l++;
		}
		if (l < i)
		{
			return -1;
		}

		if (number2 < startNumber)
		{
			return number2;
		}
		else
		{
			swap(numberArray[j], numberArray[j + 1]);
			number2 = 0;
		}
	}
	return -1;
}

void nextSmallerThanTests()
{
	cout << (nextSmallerThan(21) == 12) << endl;
	cout << (nextSmallerThan(531) == 513) << endl;
	cout << (nextSmallerThan(2071) == 2017) << endl;
	cout << (nextSmallerThan(9) == -1) << endl;
	cout << (nextSmallerThan(111) == -1) << endl;
	cout << (nextSmallerThan(135) == -1) << endl;
	cout << (nextSmallerThan(1027) == -1) << endl;
	//...
	cout << (nextSmallerThan(132) == 123) << endl;
	cout << (nextSmallerThan(583) == 538) << endl;
	cout << (nextSmallerThan(9387) == 9378) << endl;
	cout << (nextSmallerThan(61037) == 60137) << endl;
	cout << (nextSmallerThan(31568) == 13568) << endl;
}

void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

int arrayToNumber(int array[], int i)
{
	int number = 0;
	for (int k = 0; k < i; k++)
	{
		number += array[k] * pow(10, k);
	}
	return number;
}