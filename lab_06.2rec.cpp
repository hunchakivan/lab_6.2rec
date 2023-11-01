#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i) {
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i) {
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

int Avg(int* a, const int size, int i, int S, int Q) {
	if (i >= size) {
		if (Q == 0)
			return 0.0;
		return (double)S / Q;
	}
	if (a[i] % 2 != 0) {
		S += a[i];
		Q += 1;
	}
	return Avg(a, size, i + 1, S, Q);
}

int main() {
	srand((unsigned)time(NULL));
	const int n = 25;
	int a[n];
	int Low = 1;
	int High = 100;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "Avg = " << Avg(a, n, 0, 0, 0) << endl;
	return 0;
}