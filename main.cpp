#include <iostream>

#include "sorting.h"
#include "methods.h"

using namespace std;

int main(){
    
    double small[500][11];
    double big[2000][51]; 

    // forwardSelectionSmall(small);
    readSmall(small);
    forwardSelectionSmall(small);

    return 0;
}