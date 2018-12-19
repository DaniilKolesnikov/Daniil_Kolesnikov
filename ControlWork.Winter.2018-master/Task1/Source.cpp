#include <iostream>

using namespace std;

int nextSmallerThan(int);
void nextSmallerThanTests();
void numberToArray(int, int[], int);
void swap(int& x, int& y);

int main()
{
	int number;
	cout << "enter positive number: ";
	cin >> number;
	cout << endl;

	cout << nextSmallerThan;
	
	nextSmallerThanTests();
	
}

int nextSmallerThan(int number)
{
	int numberArray[10] = { 0 }, i = 0, number2 = 0;

	while (number > 0)
	{
		numberArray[i] = number % 10;
		number /= 10;
		i++;
	}

	for (int j = 0; j < i; j++)
	{
		swap(numberArray[j], numberArray[j + 1]);
		for (int k = 0; k < i; k++)
		{
			number2 = number2 + numberArray[k] * pow(10, k + 1);
		}
		if (number2 < number)
		{
			return number2;
		}
		else
		{
			swap(numberArray[j + 1], numberArray[j]);
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
}

void numberToArray(int number, int array[],int i)
{
	while (number > 0)
	{
		array[i] = number % 10;
		number /= 10;
		i++;
	}
}

void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}