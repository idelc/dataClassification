#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

void readData(double data[][11], string fName){
    ifstream read(fName);
    if(!read.is_open()){
        cout << "Error opening " << fName << endl;
        exit(1);
    }
    double temp = 0;
    // cout.precision(9);
    for(int i = 0; i < 500; i++){ // per row
        for(int j = 0; j < 11; j++){ //column
            read >> temp;
            data[i][j] = temp;
            // cout << temp << endl;
        }
    }
    read.close();
}

void readData(double data[][51], string fName){
    ifstream read(fName);
    if(!read.is_open()){
        cout << "Error opening " << fName << endl;
        exit(1);
    }
    double temp = 0;
    // cout.precision(9);
    for(int i = 0; i < 2000; i++){ // per row
        for(int j = 0; j < 51; j++){ //column
            read >> temp;
            data[i][j] = temp;
            // cout << temp << endl;
        }
    }
    read.close();
}

void readData(double data[][17]){
    ifstream read("beanData.txt");
    if(!read.is_open()){
        cout << "Error opening file" << endl;
        exit(1);
    }
    double temp = 0;
    // cout.precision(9);
    for(int i = 0; i < 13611; i++){ // per row
        for(int j = 0; j < 17; j++){ //column
            read >> temp;
            data[i][j] = temp;
            // cout << temp << endl;
        }
    }
    read.close();
}


#endif