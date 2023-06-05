#include <iostream>
#include <windows.h>

#include "MyArray.h"

using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size = 9;
	int* arr = new int[size] { 0, 1, 2, 3, 4, 5, 6, 8, 9 };

	MyArray array(size, arr);	
	array.printArray();

	array.resize(10);
	array.printArray();

	array.initArrayWithRandValue(1, 9);
	array.printArray();

	array.sortArray();
	array.printArray();

	int minVal = array.minValue();
	cout << "min value = " << minVal << endl;

	int maxVal = array.maxValue();
	cout << "max value = " << maxVal << endl;

	cout << endl << array;

	delete[]arr;

	return 0;
}