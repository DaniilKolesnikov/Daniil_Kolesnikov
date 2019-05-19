#include <iostream>
#include <ctime>

using namespace std;

void fillArray(int*, int);
void showArray(int*, int);
void findElements(int*, int*, int*, int, int&);
void mergeSort(int*, int);

int main()
{
	srand(time(NULL));

	int size;
	cout << "enter the length of array: ";
	cin >> size;
	system("cls");

	int* arr = new int[size];

	fillArray(arr, size);

	showArray(arr, size);
	cout << "\n";
	cout << "===========================================================" << endl;

	int* arr1 = new int[size];
	int size2 = 100;
	int* arr2 = new int[size2];
	findElements(arr, arr1, arr2, size, size2);

	showArray(arr2, size2);
	cout << "\n";
	cout << "===========================================================" << endl;

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

}