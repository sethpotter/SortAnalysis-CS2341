#include "ArrayWrapper.h"
#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * Move constructor. Initializes srand for shuffle method.
 * @param array Array on the stack.
 * @param size Size of the array.
 */
ArrayWrapper::ArrayWrapper(int* array, int size) : array(array), size(size) {
    srand(time(NULL));
};

/**
 * Subscript operator. Provides out of bounds checking.
 * @param i Index
 * @return value
 */
int& ArrayWrapper::operator [] (int i) {
    if(i >= size || i < 0) {
        throw out_of_range("ArrayWrapper [] out of bounds.");
    }
    return array[i];
}

/**
 * Shuffles the content of the array using rand()
 */
void ArrayWrapper::shuffle() {
    int currIndex = size;

    while(currIndex != 0) {
        int randIndex = (rand() % currIndex);
        currIndex--;

        int temp = array[currIndex];
        array[currIndex] = array[randIndex];
        array[randIndex] = temp;
    }
}

/**
 * Populates the array.
 * Sets each element in the array equal to its index.
 */
void ArrayWrapper::populate() {
    for(int i = 0; i < size; i++)
        array[i] = i;
}

/**
 * Reverses the array.
 */
void ArrayWrapper::reverse() {
    for(int i = 0; i < size / 2; i++) {
        int temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

/**
 * Prints out a nicely formatted array.
 */
void ArrayWrapper::print() {
    cout << "[";
    for (int i = 0; i < size - 1; i++)
        cout << array[i] << ", ";
    cout << array[size - 1] << "]" << endl;
}

/**
 * Swaps two elements contained at index a and b.
 * @param a Index 1
 * @param b Index 2
 */
void ArrayWrapper::swap(int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

/**
 * @return The size of the array.
 */
int ArrayWrapper::length() const {
    return size;
}

/**
 * @return The integer array itself.
 */
int* ArrayWrapper::getArray() {
    return array;
}