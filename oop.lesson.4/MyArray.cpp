#include "MyArray.h"

MyArray::MyArray() : MyArray(10, 0) {}

MyArray::MyArray(int size, int value) {

    this->size = size;
    array = new int[size];

    for (int i = 0; i < size; i++)
        array[i] = value;
}

MyArray::MyArray(int size, int* array) {

    this->size = size;
    this->array = new int[size];

    for (int i = 0; i < size; i++)
        this->array[i] = array[i];
}

MyArray::~MyArray() {

    delete[] array;
}

void MyArray::initArrayWithRandValue(int min, int max) {

    srand(time(0));

    for (int i = 0; i < size; i++)
        array[i] = min + rand() % (max - min + 1);
}

void MyArray::resize(int size) {

    int* temp = new int[size];
    int i = 0;

    for (; i < this->size; i++)
        temp[i] = array[i];

    for (int j = i; j < size; j++)
        temp[j] = 0;

    delete[] array;
    this->size = size;
    array = temp;
}

void MyArray::printArray() {

    for (int i = 0; i < size; i++)
        cout << "index [" << i << "] = " << array[i] << endl;
    cout << endl;
}

void MyArray::sortArray() {

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) 

            if (array[j] > array[j + 1]) {

                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }        
    }
}

int MyArray::minValue() const {

    int minVal = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < minVal)
            minVal = array[i];
    }

    return minVal;
}

int MyArray::maxValue() const {

    int maxVal = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > maxVal)
            maxVal = array[i];
    }

    return maxVal;
}

ostream& operator<<(ostream& out, const MyArray& object)
{
    out << "overloaded: \n";
    for (int i = 0; i < object.size; i++)
        out << "index [" << i << "] = " << object.array[i] << endl;
    out << "size = " << object.size << endl;
    out << endl;

    return out;
}