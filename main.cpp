#include <iostream>
#include <ctime>
#include <string>

#include "fileRead.h"
#include "methods.h"

using namespace std;

int main(){
    
    double small[500][11];
    double big[2000][51]; 
    double bean[13611][17];
    
    // cout << "Bean data: ";
    // for(unsigned i = 0; i<17; i++){
    //     cout << ' ' <<bean[0][i]; 
    // }
    // cout << endl;

    cout << "Welcome to the dataClassiciation program for CS170, Fall 2021" << endl << endl;
    cout << "Choose an option:\n";
    cout << "1. Run big forwards\n";
    cout << "2. Run small forwards\n";
    cout << "3. Run big backwards\n";
    cout << "4. Run small backwards\n";
    cout << "5. Run beans\n";
    cout << "0. Exit\n";

    unsigned answer = 0;
    string fileName = "";
    clock_t runTime;
    cin >> answer;
    switch (answer){
    case 1:
        cout << "Running big forward. File name?: ";
        cin >> fileName;
        cout << endl;
        readData(big, fileName);
        runTime = clock();
        forwardSelection(big);
        cout << "\nCPU time (linux only): " << static_cast<double>((clock()-runTime))/CLOCKS_PER_SEC << " seconds" << endl;
        break;
    case 2:
        cout << "Running small forward. File name?: ";
        cin >> fileName;
        cout << endl;
        readData(small,fileName);
        runTime = clock();
        forwardSelection(small);
        cout << "\nCPU time (linux only): " << static_cast<double>((clock()-runTime))/CLOCKS_PER_SEC << " seconds" << endl;
        break;
    case 3:
        cout << "Running big backward. File name?: ";
        cin >> fileName;
        cout << endl;
        readData(big, fileName);
        runTime = clock();
        backwardElimination(big);
        cout << "\nCPU time (linux only): " << static_cast<double>((clock()-runTime))/CLOCKS_PER_SEC << " seconds" << endl;
        break;
    case 4:
        cout << "Running small backward. File name?: ";
        cin >> fileName;
        cout << endl;
        readData(small,fileName);
        runTime = clock();
        backwardElimination(small);
        cout << "\nCPU time (linux only): " << static_cast<double>((clock()-runTime))/CLOCKS_PER_SEC << " seconds" << endl;
        break;
    case 5: 
        cout << "Running beans" << endl;
        readData(bean);
        runTime = clock();
        forwardSelection(bean);
        cout << "\nCPU time (linux only): " << static_cast<double>((clock()-runTime))/CLOCKS_PER_SEC << " seconds" << endl;
        break;
    default:
        cout << "Bye!" << endl;
        exit(0);
        break;
    }

    return 0;
}