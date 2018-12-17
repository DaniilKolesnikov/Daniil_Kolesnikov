#include <iostream>

using namespace std;

void initMatrixA(int[][100], int);
void initMatrixB(int[][100], int);
void initMatrixC(int[][100], int);
void initMatrixD(int[][100], int);
void displayMatrix(int[][100], int);
void swap(int& x, int& y);
void transpose(int a[][100], int n);

int main()
{
	int matrix[100][100] = { {0} }, n;
	cout << "enter n: ";
	cin >> n;

	//initMatrixA(matrix, n);
	//initMatrixB(matrix, n);
	//initMatrixC(matrix, n);
	initMatrixD(matrix, n);
	displayMatrix(matrix, n);

	system("pause");
	return 0;
}

void initMatrixA(int matrix[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) 
			{
				/*matrix[i][j] = n;
				matrix[i][j - 1] = n - 1;*/
				for (int a = 0; a < j+1; a++)
				{
					matrix[i][j - a] = n - a;
				}
			}

		}
	}
}

void initMatrixB(int matrix[][100], int n)
{
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		for (int j = i; j < n - i; j++)
		{
			matrix[i][j] = 1;
		}
	}
	int k = (n + 1) / 2 - 1;
	for (int i = (n + 1) / 2; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = matrix[k][j];
		}
		k = k - 1;
	}
}

void initMatrixC(int matrix[][100], int n)
{
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		for (int j = i; j < n - i; j++)
		{
			matrix[i][j] = 1;
		}
	}
	int k = (n + 1) / 2 - 1;
	for (int i = (n + 1) / 2; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = matrix[k][j];
		}
		k = k - 1;
	}
	transpose(matrix, n);
}

void initMatrixD(int matrix[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				matrix[i][j] = i + 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][n - i - 1] = n - i;
		}
	}
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

void transpose(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			swap(a[i][j], a[j][i]);
		}

	}
}

void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}