#include <iostream>
#include <ctime>

#include "fileRead.h"
#include "methods.h"

using namespace std;

int main(){
    
    double small[500][11];
    double big[2000][51]; 

    readData(small);
    
    clock_t runTime = clock();
    backwardElimination(small);
    cout << "\nCPU time (linux only): " << static_cast<double>((clock()-runTime))/CLOCKS_PER_SEC << " seconds" << endl;

    runTime = clock();
    forwardSelection(small);
    cout << "\nCPU time (linux only): " << static_cast<double>((clock()-runTime))/CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}