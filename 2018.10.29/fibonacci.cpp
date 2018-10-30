using namespace std;

#include <iostream>

int main()
{
	int a = 1, b = 2, c = 3;
	while (true)
	{
		a = b;
		b = c;
		c = a + b;
		if (c > 1000)
			break;
	}
	cout << "the smallest three-digit Fibonacci number is " << c << endl;
	system("pause");
	return 0;
}