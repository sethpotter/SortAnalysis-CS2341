#include "OutputCsv.h"
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    if(argc == 3)
    {
        if(strcmp(argv[1], "-l") == 0) /// Run local environment. More datasets.
        {
            int sizes[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
            OutputCsv out(argv[2]);
            out.write(sizes, 10);
            cout << "Done" << endl;
        }
        else if(strcmp(argv[1], "-g") == 0) /// Run github environment.
        {
            int sizes[] = { 10, 50, 100 };
            OutputCsv out(argv[2]);
            out.write(sizes, 3);
            cout << "Done" << endl;
        }
        else
        {
            throw runtime_error("Invalid arguments.");
        }
    }
    else
    {
        throw runtime_error("Not enough arguments.");
    }
    return 0;
}