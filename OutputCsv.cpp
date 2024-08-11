#include "OutputCsv.h"
#include <vector>

using namespace std;

/**
 * Constructor.
 * @param file Output file name.
 */
OutputCsv::OutputCsv(char *file) {
    out = new ofstream(file);

    if(!out->is_open() || !out->good())
        throw runtime_error("Error could not generate output file.");
}

/**
 * Destructor.
 */
OutputCsv::~OutputCsv() {
    out->close();
    delete out;
}

/**
 * Writes the CSV output file.
 * @param sizes Array of sizes for datasets to generate.
 * @param numberOfSets Number of sets to generate.
 */
void OutputCsv::write(const int* sizes, int numberOfSets) {
    /// Output header columns.
    *out << "Sorted,";
    for(int i = 0; i < numberOfSets; i++)
        *out << "Set " << i + 1 << ",";
    *out << "Reversed,";
    for(int i = 0; i < numberOfSets; i++)
        *out << "Set " << i + 1 << ",";
    *out << "Shuffled,";
    for(int i = 0; i < numberOfSets; i++) {
        if(i == numberOfSets - 1)
            *out << "Set " << i + 1;
        else
            *out << "Set " << i + 1 << ",";
    }
    *out << endl;

    /// Outer for-loop is for each algorithm.
    for(int i = 0; i < 6; i++) {

        /// Sadly had to use this for some formatting issues. Basically just loading
        /// some data in here and printing it out to the file.
        vector<int> sortComp;
        vector<int> reverseComp;
        vector<int> shuffleComp;

        for(int j = 0; j < numberOfSets; j++) {
            int s = sizes[j];
            int array[s];

            /// Create wrapper object and sort object.
            ArrayWrapper aw(array, s);
            Sorter sort(aw);

            /// Fill array with numbers.
            aw.populate();
            pickSort(sort, i);
            sortComp.push_back(sort.reset());

            /// Reverse sorted array.
            aw.reverse();
            pickSort(sort, i);
            reverseComp.push_back(sort.reset());

            /// Shuffle array
            aw.shuffle();
            pickSort(sort, i);
            shuffleComp.push_back(sort.reset());
        }

        /// Print from vectors.
        *out << pickName(i) << ",";
        for(int j = 0; j < sortComp.size(); j++) {
            *out << sortComp[j] << ",";
        }
        *out << pickName(i) << ",";
        for(int j = 0; j < reverseComp.size(); j++) {
            *out << reverseComp[j] << ",";
        }
        *out << pickName(i) << ",";
        for(int j = 0; j < shuffleComp.size(); j++) {
            if(j == shuffleComp.size() - 1)
                *out << shuffleComp[j];
            else
                *out << shuffleComp[j] << ",";
        }
        *out << endl;
    }

}

/**
 * Used to help format the output for CSV file.
 * @return Sorting algorithm name
 */
char * OutputCsv::pickName(int name) {
    switch(name) {
        case 0:
            return "Bubble Sort";
        case 1:
            return "Selection Sort";
        case 2:
            return "Insertion Sort";
        case 3:
            return "Quick Sort";
        case 4:
            return "Merge Sort";
        case 5:
            return "Heap Sort";
        default:
            break;
    }
    return "null";
}

/**
 * Used to help format the output for CSV file.
 * @param sorter Sorter object
 * @param method Sorting algorithm to use.
 */
void OutputCsv::pickSort(Sorter &sorter, int method) {
    switch(method) {
        case 0:
            sorter.bubbleSort();
            break;
        case 1:
            sorter.selectionSort();
            break;
        case 2:
            sorter.insertionSort();
            break;
        case 3:
            sorter.quickSort();
            break;
        case 4:
            sorter.mergeSort();
            break;
        case 5:
            sorter.heapSort();
            break;
        default:
            break;
    }
}