#include <iostream>

using namespace std;

void displayMatrix(int[][100], int, int);
void initMatrix(int[][100], int, int);
void swap(int& x, int& y);
void columnSwap(int[][100], int, int);

int main()
{
	int matrix[100][100] = { {0} }, n, m;

	cout << "enter n: ";
	cin >> n;
	cout << "enter m: ";
	cin >> m;

	initMatrix(matrix, n, m);
	displayMatrix(matrix, n, m);

	cout << endl;
	cout << endl;

	columnSwap(matrix, n, m);
	displayMatrix(matrix, n, m);

	system("pause");
	return 0;
}

void displayMatrix(int matrix[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(5);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

void initMatrix(int matrix[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = i + 1;
		}
	}
}

void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

void columnSwap(int matrix[][100], int n, int m)
{
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		for (int j = 0; j < m; j++)
		{
			swap(matrix[i][j], matrix[n-i-1][j]);
		}
	}
}