#ifndef OUTPUTCSV_H
#define OUTPUTCSV_H

#include <fstream>
#include "Sorter.h"

using namespace std;

/**
 * OutputCsv class. Runs the sorting algorithms and generates the CSV Output file.
 */
class OutputCsv {
public:
    /// Constructor.
    explicit OutputCsv(char* file);

    /// Destructor.
    ~OutputCsv();

    /// Documentation in OutputCsv.cpp
    void write(const int* sizes, int numberOfSets);
    char* pickName(int name);
    void pickSort(Sorter &sorter, int method);
private:
    ofstream* out;
};

#endif //OUTPUTCSV_H
