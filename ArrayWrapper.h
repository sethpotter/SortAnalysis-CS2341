#ifndef ARRAYWRAPPER_H
#define ARRAYWRAPPER_H

#include <ctime>
#include <cstdlib>

/**
 * ArrayWrapper class. Provides basic wrapper methods (Swap, Reverse, Shuffle.. etc.)
 * for a Integer C-style array. This wrapper was intended for arrays on the stack. Not the heap.
 */
class ArrayWrapper {
public:
    /// Move constructor.
    ArrayWrapper(int* array, int size);

    /// Subscript operator.
    int& operator [] (int i);

    /// Documentation provided in ArrayWrapper.cpp
    void shuffle();
    void populate();
    void reverse();
    void print();
    void swap(int a, int b);
    int length() const;
    int* getArray();
private:
    int* array = nullptr;
    int size;
};

#endif //ARRAYWRAPPER_H
