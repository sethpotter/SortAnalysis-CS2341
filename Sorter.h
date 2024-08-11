#ifndef SORTER_H
#define SORTER_H

#include "ArrayWrapper.h"

/**
 * Sorter class. Provides various sorting methods for an array and a counter for comparisons.
 */
class Sorter {
public:
    /// Move constructor.
    explicit Sorter(ArrayWrapper &array);

    /// Sorting methods. Documentation provided in Sorter.cpp.
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void quickSort();
    void mergeSort();
    void heapSort();

    /// Print and reset
    int reset();
private:
    ArrayWrapper &array;
    int comparisons = 0;

    /// Method(s) used in HeapSort.
    void heapify(int n, int i);

    /// Method(s) used in QuickSort.
    void quickSort(int low, int high);
    int partition(int low, int high);

    /// Method(s) used in MergeSort.
    void mergeSort(int l, int r);
    void merge(int l, int m, int r);
};

#endif //SORTER_H
