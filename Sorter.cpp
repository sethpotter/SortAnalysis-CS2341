#include "Sorter.h"
#include <iostream>

using namespace std;

Sorter::Sorter(ArrayWrapper &array) : array(array) {};

/**
 * Bubble Sort.
 * Time Complexity Best O(n) Worst O(n^2)
 */
void Sorter::bubbleSort() {
    bool swapped = false;
    for(int i = 0; i < array.length() - 1; i++) {
        for(int j = 0; j < array.length() - i - 1; j++) {
            comparisons++;
            if(array[j] > array[j + 1])
            {
                array.swap(j, j + 1);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}

/**
 * Selection Sort.
 * Time Complexity Best O(n^2) Worst O(n^2)
 */
void Sorter::selectionSort() {
    for(int i = 0; i < array.length() - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < array.length(); j++) {
            comparisons++;
            if(array[j] < array[minIndex])
                minIndex = j;
        }
        array.swap(minIndex, i);
    }
}

/**
 * Insertion Sort.
 * Time Complexity Best O(n) Worst O(n^2)
 */
void Sorter::insertionSort() {
    for(int i = 1; i < array.length(); ++i) {
        int key = array[i];
        int j = i - 1;

        comparisons++;
        bool skipFirst = false;
        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
            if(!skipFirst) {
                skipFirst = true;
            } else {
                comparisons++;
            }
        }
        array[j + 1] = key;
    }
}

/**
 * Quick Sort.
 * Time Complexity Best O(n log n) Worst O(n^2)
 */
void Sorter::quickSort() {
    quickSort(0, array.length() - 1);
}

/**
 * Merge Sort.
 * Time Complexity Best O(n log n) Worst O(n log n)
 */
void Sorter::mergeSort() {
    mergeSort(0, array.length() - 1);
}

/**
 * Heap Sort.
 * Time Complexity Best O(n log n) Worst (n log n)
 */
void Sorter::heapSort() {
    for(int i = array.length() / 2; i >= 0; i--)
        heapify(array.length(), i);
    for(int i = array.length() - 1; i > 0; i--) {
        array.swap(0, i);

        heapify(i, 0);
    }
}

/**
 * Returns the number of comparisons and resets to zero.
 */
int Sorter::reset() {
    int temp = comparisons;
    comparisons = 0;
    return temp;
}

/**
 * Method(s) used in Heap Sort.
 */
void Sorter::heapify(int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && array[l] > array[largest])
        largest = l;
    if(r < n && array[r] > array[largest])
        largest = r;

    comparisons++;
    if(largest != i) {
        array.swap(i, largest);
        heapify(n, largest);
    }
}

/**
 * Method(s) used in Quick Sort.
 */
void Sorter::quickSort(int low, int high) {
    if(low < high) {
        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

/**
 * Method(s) used in Quick Sort.
 */
int Sorter::partition(int low, int high) {
    int pivot = array[high];

    int i = (low - 1);
    for(int j = low; j <= high - 1; j++) {
        comparisons++;
        if(array[j] < pivot) {
            i++;
            array.swap(i, j);
        }
    }
    array.swap(i + 1, high);
    return i + 1;
}

/**
 * Method(s) used in Merge Sort.
 */
void Sorter::mergeSort(int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;

        mergeSort(l, m);
        mergeSort(m + 1, r);

        merge(l, m, r);
    }
}

/**
 * Method(s) used in Merge Sort.
 */
void Sorter::merge(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1];
    int right[n2];

    for(int i = 0; i < n1; ++i)
        left[i] = array[l + i];
    for(int i = 0; i < n2; ++i)
        right[i] = array[m + 1 + i];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        comparisons++;
        if(left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        array[k] = left[i];
        i++;
        k++;
    }

    while(j < n2) {
        array[k] = right[j];
        j++;
        k++;
    }
}