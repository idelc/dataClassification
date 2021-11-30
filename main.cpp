#include <iostream>

#include "sorting.h"

using namespace std;

int main(){
    
    double small[500][11];
    double big[2000][51]; 
    readSmall(small);
    cout << small[415][1] << endl;

    readBig(big);
    cout << big[415][1] << endl;

    return 0;
}