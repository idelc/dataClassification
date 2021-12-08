#include <iostream>

#include "fileRead.h"
#include "methods.h"

using namespace std;

int main(){
    
    double small[500][11];
    double big[2000][51]; 

    readData(small);
    backwardElimination(small);
    forwardSelection(small);

    return 0;
}