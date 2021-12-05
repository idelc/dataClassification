#include <iostream>

#include "fileRead.h"
#include "methods.h"

using namespace std;

int main(){
    
    double small[500][11];
    double big[2000][51]; 

    readData(small);
    forwardSelection(small);
    readData(big);
    forwardSelection(big);

    return 0;
}