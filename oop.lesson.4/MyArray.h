#include <iostream>
#include <windows.h>

using namespace std;

class MyArray {

    int size;
    int* array;

public:
    MyArray();
    MyArray(int size, int value);
    MyArray(int size, int* array);
    ~MyArray();

    void initArrayWithRandValue(int min, int max);
    void resize(int size);
    void printArray();
    void sortArray();
    int minValue() const;
    int maxValue() const;

    friend ostream& operator<<(ostream& out, const MyArray& object);
};