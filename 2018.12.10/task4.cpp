#include <iostream>

using namespace std;

void displayMatrix(int[][100], int);
void initArray(int[], int);
void initMatrix(int[][100], int[], int);
void arrayShift(int[], int);

int main()
{
	int array[100] = { 0 }, matrix[100][100] = { {0} }, n;
	
	cout << "enter n: ";
	cin >> n;

	initArray(array, n);
	initMatrix(matrix, array, n);
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

void initArray(int array[], int n)
{
	array[0] = 1;
	for (int i = 0; i < n; i++)
	{
		array[i + 1] = array[i] + 1;
	}
}

void initMatrix(int matrix[][100], int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = array[j];
		}
		arrayShift(array, n);
	}
}

void arrayShift(int array[], int n)
{
	int arrayX[100] = { 0 };
	
	for (int i = 0; i < n; i++)
	{
		arrayX[i] = array[i + 1];
	}
	arrayX[n - 1] = array[0];
	for (int i = 0; i < n; i++)
	{
		array[i] = arrayX[i];
	}
}
