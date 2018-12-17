#include <iostream>

using namespace std;

void displayMatrix(int[][100], int);
void initMatrix(int[][100], int);
void swap(int& x, int& y);
void swapSquares(int[][100], int);

int main()
{
	int matrix[100][100] = { {0} }, n;

	cout << "enter n: ";
	cin >> n;

	initMatrix(matrix, n);
	swapSquares(matrix, n);
	displayMatrix(matrix, n);

	system("pause");
	return 0;
}

void displayMatrix(int matrix[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(5);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

void initMatrix(int matrix[][100], int n)
{
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		for (int j = 0; j < (n + 1) / 2; j++)
		{
			matrix[i][j] = 1;
		}

		for (int j = (n + 1) / 2; j < n; j++)
		{
			matrix[i][j] = 2;
		}

	}
	for (int i = (n + 1) / 2; i < n; i++)
	{
		for (int j = 0; j < (n + 1) / 2; j++)
		{
			matrix[i][j] = 3;
		}

		for (int j = (n + 1) / 2; j < n; j++)
		{
			matrix[i][j] = 4;
		}

	}
}

void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

void swapSquares(int matrix[][100], int n)
{
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		for (int j = 0; j < (n + 1) / 2; j++)
		{
			swap(matrix[i][j], matrix[(n + 1) / 2 + i][(n + 1) / 2 + j]);
		}
	}
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		for (int j = (n + 1) / 2; j < n; j++)
		{
			swap(matrix[i][j], matrix[(n + 1) / 2 + i][j - (n + 1) / 2]);
		}
	}
}