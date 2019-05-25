#include <iostream>
#include <ctime>

using namespace std;

int* allocateMemory(int);
int** allocateMemoryMatrix(int, int*);
int* inputSizes(int);
void fillMatrix(int**, int, int*);
void showMatrix(int**, int, int*);
void showArray(int*, int);
void findElements(int*, int*, int*, int&, int&);
void findElementsMatrix(int**, int**, int**, int, int*, int*);
int remainder(int);
void mergeSort(int*, int);
void merge(int*, int*, int*, int, int);
void sortMatrix(int**, int, int*);

int main()
{
	srand(time(NULL));

	cout << "enter the number of rows: ";
	int rows;
	cin >> rows;
	cout << "\n\n";

	int* sizes = inputSizes(rows);
	system("cls");

	int** matrix = allocateMemoryMatrix(rows, sizes);
	fillMatrix(matrix, rows, sizes);

	cout << "starting matrix:\n\n";
	showMatrix(matrix, rows, sizes);
	cout << "\n===================================================================================================\n\n";

	int** matrix1 = allocateMemoryMatrix(rows, sizes);
	int** matrix2 = allocateMemoryMatrix(rows, sizes);
	int* sizes2 = allocateMemory(rows);

	findElementsMatrix(matrix, matrix1, matrix2, rows, sizes, sizes2);

	cout << "new matrix:\n\n";
	showMatrix(matrix2, rows, sizes2);
	cout << "\n===================================================================================================\n\n";

	cout << "old matrix:\n\n";
	showMatrix(matrix1, rows, sizes);
	cout << "\n===================================================================================================\n\n";

	sortMatrix(matrix1, rows, sizes);

	cout << "sorted matrix:\n\n";
	showMatrix(matrix1, rows, sizes);
	cout << "\n===================================================================================================\n\n";

	delete[] matrix1;
	delete[] matrix2;
	system("pause");
	return 0;
}

int* allocateMemory(int n)
{
	if (n <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	int* array = new int[n];

	return array;
}

int** allocateMemoryMatrix(int rows, int* size)
{
	if (rows <= 0)
	{
		throw invalid_argument("Number of rows in a matrix can not be less or equal to 0.");
	}
	if (size == nullptr)
	{
		throw invalid_argument("Dimension array can not be null.");
	}

	int** matrix = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[size[i]];
	}

	return matrix;
}

int* inputSizes(int rows)
{
	int* size = new int[rows];

	cout << "Enter number of elements in a row..." << endl;

	for (int i = 0; i < rows; i++)
	{
		cout << "Row " << i + 1 << ": ";
		cin >> size[i];

		if (size[i] <= 0)
		{
			throw invalid_argument("Number of elements in a row can not be less than 0.");
		}
	}

	return size;
}

void fillMatrix(int** matrix, int rows, int* size)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < size[i]; j++)
		{
			*(*(matrix + i) + j) = rand() % 100 + 1;
		}
	}
}

void showMatrix(int** matrix, int rows, int* size)
{
	for (int i = 0; i < rows; i++)
	{
		showArray(matrix[i], size[i]);
		cout << endl;
	}
}

void showArray(int* arr, int size)
{
	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
}

void findElements(int* arr, int* arr1, int* arr2, int& size, int& size2)
{
	int j = 0, k = 0;
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0 && arr[i] % 2 == 0)
		{
			arr2[j] = arr[i];
			j += 1;
		}
		else
		{
			arr1[k] = arr[i];
			k++;
		}
	}
	size2 = j;
	size = size - size2;
	//delete[] arr;
}

void findElementsMatrix(int** matrix , int** matrix1, int** matrix2, int rows, int* sizes, int* sizes2)
{
	for (int i = 0; i < rows; i++)
	{
		findElements(matrix[i], matrix1[i], matrix2[i], sizes[i], sizes2[i]);
	}
	delete[] matrix;
}

int remainder(int number)
{
	return number % 3;
}

void mergeSort(int* arr, int size)
{

	if (size > 1)
	{
		int p = size / 2 + size % 2;
		int q = size / 2;

		int* left = allocateMemory(p);
		int* right = allocateMemory(q);

		for (int i = 0; i < p; i++)
		{
			left[i] = arr[i];
		}
		for (int j = 0; j < q; j++)
		{
			right[j] = arr[p + j];
		}
		mergeSort(left, p);
		mergeSort(right, q);
		merge(arr, left, right, p, q);
	}
	else
		return;
}

void merge(int* arr, int* left, int* right, int p, int q)
{
	int j = 0, k = 0;

	for (int i = 0; i < p + q; i++)
	{
		if (j == p)
		{
			arr[i] = right[k];
			k++;
		}
		else if (k == q)
		{
			arr[i] = left[j];
			j++;
		}
		else if (remainder(left[j]) > remainder(right[k]))
		{
			arr[i] = left[j];
			j++;
		}
		else
		{
			arr[i] = right[k];
			k++;
		}
	}
}

void sortMatrix(int** matrix, int rows, int* sizes)
{
	for (int i = 0; i < rows; i++)
	{
		mergeSort(matrix[i], sizes[i]);
	}
}