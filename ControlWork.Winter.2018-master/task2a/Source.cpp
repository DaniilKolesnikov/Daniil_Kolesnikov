#include <iostream>

using namespace std;

void encoding(char[], int[], char[]);
void decoding(int[], char[], char[]);
void codingTests();
bool equals(char[], char[]);

int main()
{
	codingTests();
}

void encoding(char source[], int encoding[], char rule[])
{
	for (int i = 0; i < length; i++)
	{

	}
}

void decoding(int source[], char decoding[], char rule[])
{
	// TODO
}

bool equals(char lhs[], char rhs[])
{
	// TODO

	return true;
}

void codingTests()
{
	const int length = 30;

	char source[length] = "learn c++!";

	int numbers[length - 1] = { 0 };

	char rule[length] = "zyxwvutsrqponmlkjihgfedcba!+ ";

	encoding(source, numbers, rule);

	char expected[length];

	decoding(numbers, expected, rule);

	cout << equals(source, expected) << endl;

	//...
}