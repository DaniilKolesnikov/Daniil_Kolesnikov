using namespace std;

#include <iostream>
#include "Library.h"

void numberOfEachDigit(long long);
void greatestDigit(long long);
void smallestDigit(long long);

int main()
{
	long long number;
	cout << "enter your number: \n";
	cin >> number;
	numberOfEachDigit(number);
	greatestDigit(number);
	smallestDigit(number);
	system("pause");
	return 0;
}

void numberOfEachDigit(long long number)
{
	for (int i = 0; i < 10; i++)
	{
		int n=0;
		long long helpnumber = number;
		while (helpnumber!=0)
		{
			if (helpnumber % 10 == i)
				n++;
			helpnumber /= 10;
		}
		cout << "number of " << i << " - " << n << endl;
	}
}

void greatestDigit(long long number)
{
	int max=0;
	long long helpnumber = number;
	while (helpnumber!=0)
	{
		if (helpnumber % 10 > max)
			max = helpnumber % 10;
		helpnumber /= 10;
	}
	cout << "greatest digit is " << max << endl;
}

void smallestDigit(long long number)
{
	int min = 10;
	long long helpnumber = number;
	while (helpnumber != 0)
	{
		if (helpnumber % 10 < min)
			min = helpnumber % 10;
		helpnumber /= 10;
	}
	cout << "smallest digit is " << min << endl;
}