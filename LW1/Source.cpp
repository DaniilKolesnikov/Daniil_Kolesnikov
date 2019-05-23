#include <iostream>
#include <ctime>

using namespace std;

void fillArray(int*, int);
void showArray(int*, int);
void findElements(int*, int*, int*, int, int&);
void mergeSort(int*, int);
void merge(int*, int*, int*, int, int);
int* allocateMemory(int);
int remainder(int);

int main()
{
	srand(time(NULL));

	int size;
	cout << "enter the length of array: ";
	cin >> size;
	system("cls");

	int* arr = allocateMemory(size);

	fillArray(arr, size);

	cout << "starting array:" << endl;
	showArray(arr, size);
	cout << "\n";
	cout << "===========================================================" << endl;

	int* arr1 = allocateMemory(size);
	int size2 = 100;
	int* arr2 = allocateMemory(size2);
	findElements(arr, arr1, arr2, size, size2);

	cout << "new array:" << endl;
	showArray(arr2, size2);
	cout << "\n";
	cout << "===========================================================" << endl;

	cout << "old array:" << endl;
	showArray(arr1, size - size2);
	cout << "\n";
	cout << "===========================================================" << endl;

	mergeSort(arr1, size - size2);

	cout << "sorted array:" << endl;
	showArray(arr1, size - size2);
	cout << "\n";

	delete[] arr1;
	delete[] arr2;

	system("pause");

	return 0;
}

void fillArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
}

void showArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "#" << i + 1 << "\t";
	}
	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
}

void findElements(int* arr, int* arr1, int* arr2, int size, int& size2)
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
	delete[] arr;
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

int* allocateMemory(int n)
{
	if (n <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");
	}

	int* array = new int[n];

	return array;
}

int remainder(int number)
{
	return number % 3;
}