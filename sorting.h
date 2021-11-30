#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

double* readSmall(){
    ifstream read("Ver_2_CS170_Fall_2021_Small_data__61.txt");
    if(!read.is_open()){
        cout << "Error opening file" << endl;
        exit(1);
    }
    static double data [500][11];
    double temp = 0;
    cout.precision(9);
    for(unsigned i = 0; i < 500; i++){ // per row
        for(unsigned j = 0; j < 11; j++){ //column
            read >> temp;
            data[i][j] = temp;
            // cout << temp << endl;
        }
    }
    read.close();
    return *data;
}

#endif