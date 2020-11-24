//рекурсивний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		create(a, size, Low, High, i + 1);
}

void print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		print(a, size, i + 1);
	else
		cout << endl;
}

int multiply(int* a, const int size, int i, int M)
{
	if (i == size) {
		return M;
	}
	else
		if (a[i] < 0) {
			M *= a[i];
			i++;
			multiply(a, size, i, M);
		}
		else {
			i++;
			multiply(a, size, i, M);
		}
}

int findMaxElement(int* a, const int size, int i, int max)
{
	if (i == size) {
		return max;
	}
	else
		if (a[i]>max) {
			max = a[i];
			i++;
			findMaxElement(a, size, i, max);
		}
		else {
			i++;
			findMaxElement(a, size, i, max);
		}
}

int sum(int* a, const int size, int index, int suma, int max)
{
	
	if (index == size) {
		return suma;
	}
	else
		if (a[index] > 0 && a[index] != max) {
			suma += a[index];
			index++;
			sum(a, size, index, suma, max);
		}
		else {
			index++;
			sum(a, size, index, suma, max);
		}
}

void Inverse(int* a, const int n, int i)
{
	int tmp = a[i];
	a[i] = a[n - 1 - i];
	a[n - 1 - i] = tmp;
	if (i < n / 2 - 1)
		Inverse(a, n, i + 1);
}

int main()
{
	srand((unsigned)time(NULL)); 
	int n;
	cout << "Enter size of array "; cin >> n;
	int* a = new int[n];
	int low = -100;
	int high = 100;
	create(a, n, low, high, 0);
	print(a, n, 0);
	int max = findMaxElement(a, n, 0, low);
	cout << "Product =" << multiply(a, n, 0, 1) << endl;
	cout << "Suma = " << sum(a, n, 0, 0, max) << endl;
	Inverse(a, n, 0);
	print(a, n, 0);
	return 0;
}