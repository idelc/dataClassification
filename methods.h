#ifndef METHODS_H
#define METHODS_H

#include <iostream>
#include <vector>

using namespace std;

int testVal(){ // dummy validation
    return rand() % 100;
}

bool isDuplicate(int nFeat, vector<unsigned> oFeat){
    for(unsigned i = 0; i < oFeat.size(); i++){
        if(oFeat[i] == nFeat){
            return true;
        }
    }
    return false;
}

double forwardSelection(double data[][11]){ // going to need two versions as c++ wont allow for empty column 
    vector<unsigned> features; 
    
    for(unsigned i = 1; i < 11; i++){ // search through each feature
        int bestSoFar = 0, val = 0, fToAdd = -1; 
        cout << "On level " << i << ' ' << endl;
        for(unsigned j = 1; j < 11; j++){ // start from 0 because feature 1 is ID
            bool duplicate = isDuplicate(j, features);
            if(!duplicate){
                cout << "Considering feature " << j << "... ";
                val = testVal();
                cout << "accuracy is " << val << endl;
                if(val > bestSoFar){
                    bestSoFar = val;
                    fToAdd = j;
                }
            }
        }

        cout << "On level " << i << ", added feature " << fToAdd << endl << endl;
        features.push_back(fToAdd);

    }
    return 0;
}

#endif