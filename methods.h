#ifndef METHODS_H
#define METHODS_H

#include <iostream>
#include <vector>
#include <cmath>

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

double defaultRate(double data[][11]){
    int cnt1 = 0, cnt2 = 0;
    for(unsigned i = 0; i < 500; i++){
        // cout << data[i][0] << endl;
        if(static_cast<int>(data[i][0]) == 1){
            // cout << data[i][0] << " is a 1" << endl;
            cnt1++;
        }
    }
    cnt2 = 500 - cnt1;
    // cout << cnt1 << " " << cnt2 << endl;
    double retVar = (cnt1 > cnt2) ? cnt1/500.0 : cnt2/500.0; 
    return retVar;
}

double defaultRate(double data[][51]){
    int cnt1 = 0, cnt2 = 0;
    for(unsigned i = 0; i < 2000; i++){
        // cout << data[i][0] << endl;
        if(static_cast<int>(data[i][0]) == 1){
            // cout << data[i][0] << " is a 1" << endl;
            cnt1++;
        }
    }
    cnt2 = 2000 - cnt1;
    // cout << cnt1 << " " << cnt2 << endl;
    double retVar = (cnt1 > cnt2) ? cnt1/2000.0 : cnt2/2000.0; 
    return retVar;
}

double kValidation(vector<unsigned> features, int newFeat, double data[][11]){ // going to need two versions as c++ wont allow for empty column 
    // ofstream write("test.txt");
    // if(!write.is_open()){
    //     cout << "file not open" << endl;
    //     exit(1);
    // }
    unsigned numClass = 0;
    for(unsigned i = 0; i < 500; i++){ // item to compare
        double nNDist = INT32_MAX;
        int nnLoc = -1;
        double distance = 0;

        for(unsigned j = 0; j < 500; j++){ // compare to all neighbors
            distance = 0; // reset distance check for neighbor
            if(i!=j){ // if not the same item
                // write << "Ask if " << i+1 << " is nearest neighbor with " << j+1 << endl; // plus 1 since index starts at 0
                for(unsigned k = 0; k < features.size(); k++){ // features to check
                    distance += pow(data[i][features[k]] - data[j][features[k]], 2);
                    // write << distance << " for feature " << k << endl;
                }
                distance += pow(data[i][newFeat] - data[j][newFeat], 2);
                // write << distance << " for feature " << newFeat << endl;
                distance = sqrt(distance);
                // write << "Final distance: " << distance << endl; 
                if(distance < nNDist){
                    // write.precision (5);
                    // write << distance << " < " << nNDist << endl;
                    nNDist = distance;
                    nnLoc = j;
                }
            }       
        }
        if(data[i][0] == data[nnLoc][0]){
            // write << "nearest neighbor is right\n" << endl;  
            numClass++;
        }        
    }
    // write << "Accuracy: " << numClass/500.0 << endl;
    // write.close();
    // exit(0);
    return numClass/500.0;
}

double kValidation(vector<unsigned> features, int newFeat, double data[][51]){ // going to need two versions as c++ wont allow for empty column 
    // ofstream write("test.txt");
    // if(!write.is_open()){
    //     cout << "file not open" << endl;
    //     exit(1);
    // }
    unsigned numClass = 0;
    for(unsigned i = 0; i < 2000; i++){ // item to compare
        double nNDist = INT32_MAX;
        int nnLoc = -1;
        double distance = 0;

        for(unsigned j = 0; j < 2000; j++){ // compare to all neighbors
            distance = 0; // reset distance check for neighbor
            if(i!=j){ // if not the same item
                // write << "Ask if " << i+1 << " is nearest neighbor with " << j+1 << endl; // plus 1 since index starts at 0
                for(unsigned k = 0; k < features.size(); k++){ // features to check
                    distance += pow(data[i][features[k]] - data[j][features[k]], 2);
                    // write << distance << " for feature " << k << endl;
                }
                distance += pow(data[i][newFeat] - data[j][newFeat], 2);
                // write << distance << " for feature " << newFeat << endl;
                distance = sqrt(distance);
                // write << "Final distance: " << distance << endl; 
                if(distance < nNDist){
                    // write.precision (5);
                    // write << distance << " < " << nNDist << endl;
                    nNDist = distance;
                    nnLoc = j;
                }
            }       
        }
        if(data[i][0] == data[nnLoc][0]){
            // write << "nearest neighbor is right\n" << endl;  
            numClass++;
        }        
    }
    // write << "Accuracy: " << numClass/500.0 << endl;
    // write.close();
    // exit(0);
    return numClass/2000.0;
}

void forwardSelection(double data[][11]){ // going to need two versions as c++ wont allow for empty column 
    vector<unsigned> features;
    vector<double> accuVec; 
    double bestSoFar = defaultRate(data); // too high for small data 61
    // double bestSoFar = 0.5;
    double val = 0.0;
    cout << "Default rate is: " << bestSoFar << endl << endl;
    int fToAdd = -1;
    double BestLevel = 0.0;
    for(unsigned i = 1; i < 11; i++){ // search through each feature
        fToAdd = -1;
        BestLevel = 0.0;
        cout << "Level " << i << ' ' << endl;
        for(unsigned j = 1; j < 11; j++){ // start from 1 because feature 0 is ID
            bool duplicate = isDuplicate(j, features);
            if(!duplicate){
                cout << "Considering feature " << j << "...\t";
                val = kValidation(features, j, data);
                cout.precision(5);
                cout << "accuracy is " << val << endl;
                if(val > BestLevel){
                    BestLevel = val;
                    fToAdd = j;
                }
                if(bestSoFar < BestLevel){
                    bestSoFar = BestLevel;
                }
            }
        }

        if(fToAdd > 0){
            cout << "On level " << i << ", added feature " << fToAdd << endl << endl;
            accuVec.push_back(BestLevel);
            features.push_back(fToAdd);
        }
        else { cout << endl;}
    }

    cout << "\nBest Features are:";
    double bestPrint = accuVec[0];
    for(unsigned n = 0; n < features.size(); n++){ 
        if((n > 0) && (accuVec[n] > bestPrint)){
            cout << ' ' << features[n];
            bestPrint = accuVec[n];
        }
        else if(!n){
            cout << ' ' << features[n];
        }
        // else {
        //     n = features.size() + 1;
        // }
    }
    cout << "\nBest Accuracy: " << bestPrint << endl;
}


void forwardSelection(double data[][51]){ // going to need two versions as c++ wont allow for empty column 
    vector<unsigned> features;
    vector<double> accuVec; 
    double bestSoFar = defaultRate(data); // too high for small data 61
    // double bestSoFar = 0.5;
    double val = 0.0;
    cout << "Default rate is: " << bestSoFar << endl << endl;
    int fToAdd = -1;
    double BestLevel = 0.0;
    for(unsigned i = 1; i < 51; i++){ // search through each feature
        fToAdd = -1;
        BestLevel = 0.0;
        cout << "Level " << i << ' ' << endl;
        for(unsigned j = 1; j < 51; j++){ // start from 1 because feature 0 is ID
            bool duplicate = isDuplicate(j, features);
            if(!duplicate){
                cout << "Considering feature " << j << "...\t";
                val = kValidation(features, j, data);
                cout.precision(5);
                cout << "accuracy is " << val << endl;
                if(val > BestLevel){
                    BestLevel = val;
                    fToAdd = j;
                }
                if(bestSoFar < BestLevel){
                    bestSoFar = BestLevel;
                }
            }
        }

        if(fToAdd > 0){
            cout << "On level " << i << ", added feature " << fToAdd << endl << endl;
            accuVec.push_back(BestLevel);
            features.push_back(fToAdd);
        }
        else { cout << endl;}
    }

    cout << "\nBest Features are:";
    double bestPrint = accuVec[0];
    for(unsigned n = 0; n < features.size(); n++){ 
        if((n > 0) && (accuVec[n] > bestPrint)){
            cout << ' ' << features[n];
            bestPrint = accuVec[n];
        }
        else if(!n){
            cout << ' ' << features[n];
        }
        // else {
        //     n = features.size() + 1;
        // }
    }
    cout << "\nBest Accuracy: " << bestPrint << endl;
}


double kValidationRemoval(vector<unsigned> features, int newFeat, double data[][11]){ // going to need two versions as c++ wont allow for empty column 
    // ofstream write("test.txt");
    // if(!write.is_open()){
    //     cout << "file not open" << endl;
    //     exit(1);
    // }
    unsigned numClass = 0;
    for(unsigned i = 0; i < 500; i++){ // item to compare
        double nNDist = INT32_MAX;
        int nnLoc = -1;
        double distance = 0;

        for(unsigned j = 0; j < 500; j++){ // compare to all neighbors
            distance = 0; // reset distance check for neighbor
            if(i!=j){ // if not the same item
                // write << "Ask if " << i+1 << " is nearest neighbor with " << j+1 << endl; // plus 1 since index starts at 0
                for(unsigned k = 0; k < features.size(); k++){ // features to check
                    if(features[k] && (k != (newFeat-1))){
                        distance += pow(data[i][k+1] - data[j][k+1], 2);
                        // write << distance << " for feature " << k << endl;
                    }
                }

                distance = sqrt(distance);
                // write << "Final distance: " << distance << endl; 
                if(distance < nNDist){
                    // write.precision (5);
                    // write << distance << " < " << nNDist << endl;
                    nNDist = distance;
                    nnLoc = j;
                }
            }       
        }
        if(data[i][0] == data[nnLoc][0]){
            // write << "nearest neighbor is right\n" << endl;  
            numClass++;
        }        
    }
    // write << "Accuracy: " << numClass/500.0 << endl;
    // write.close();
    // exit(0);
    return numClass/500.0;
}

void backwardElimination(double data[][11]){
    vector<unsigned> features(10,1);
    // vector<double> accuVec(10);
    vector<unsigned> finalFeat; 
    // double bestSoFar = defaultRate(data); // too high for small data 61
    // double bestSoFar = 0.5;
    double bestSoFar = kValidationRemoval(features, 20, data);
    double val = 0.0;
    cout << "Default rate is: " << bestSoFar << endl << endl;
    int fToAdd = -1;
    double BestLevel = 0.0;
    for(unsigned i = 1; i < 11; i++){ // search through each feature
        fToAdd = -1;
        BestLevel = 0.0;
        cout << "Level " << i << ' ' << endl;
        for(unsigned j = 1; j < 11; j++){ // start from 1 because feature 0 is ID
            if(features[j-1]){
                cout << "Considering feature " << j << "...\t";
                val = kValidationRemoval(features, j, data);
                cout.precision(5);
                cout << "accuracy is " << val << endl;
                if(val > BestLevel){
                    BestLevel = val;
                    fToAdd = j;
                }
                if(bestSoFar < BestLevel){
                    bestSoFar = BestLevel;
                    //finalFeat.clear();
                    finalFeat = features;
                    finalFeat[j-1] = 0;
                }
            }
        }

        if(fToAdd > 0){
            cout << "On level " << i << ", removed feature " << fToAdd << endl << endl;
            // accuVec[i-1] = BestLevel;
            features[fToAdd-1]=0;
            
            cout << "\ncurrent features are: ";
            for(unsigned x = 0; x<features.size();x++){
                if(features[x]){cout << ' ' << x+1;}
            }
            cout << endl;

        }
        else { cout << endl;}
    }

    cout << "\nBest Features are:";
    for(unsigned n = 0; n<finalFeat.size(); n++){
        if(finalFeat[n]){
            cout << ' ' << n+1;
        }
    }
    cout << "\nBest Accuracy: " << bestSoFar << endl;
    
}

double kValidationRemoval(vector<unsigned> features, int newFeat, double data[][51]){ // going to need two versions as c++ wont allow for empty column 
    // ofstream write("test.txt");
    // if(!write.is_open()){
    //     cout << "file not open" << endl;
    //     exit(1);
    // }
    unsigned numClass = 0;
    for(unsigned i = 0; i < 2000; i++){ // item to compare
        double nNDist = INT32_MAX;
        int nnLoc = -1;
        double distance = 0;

        for(unsigned j = 0; j < 2000; j++){ // compare to all neighbors
            distance = 0; // reset distance check for neighbor
            if(i!=j){ // if not the same item
                // write << "Ask if " << i+1 << " is nearest neighbor with " << j+1 << endl; // plus 1 since index starts at 0
                for(unsigned k = 0; k < features.size(); k++){ // features to check
                    if(features[k] && (k != (newFeat-1))){
                        distance += pow(data[i][k+1] - data[j][k+1], 2);
                        // write << distance << " for feature " << k << endl;
                    }
                }

                distance = sqrt(distance);
                // write << "Final distance: " << distance << endl; 
                if(distance < nNDist){
                    // write.precision (5);
                    // write << distance << " < " << nNDist << endl;
                    nNDist = distance;
                    nnLoc = j;
                }
            }       
        }
        if(data[i][0] == data[nnLoc][0]){
            // write << "nearest neighbor is right\n" << endl;  
            numClass++;
        }        
    }
    // write << "Accuracy: " << numClass/500.0 << endl;
    // write.close();
    // exit(0);
    return numClass/2000.0;
}

void backwardElimination(double data[][51]){
    vector<unsigned> features(50,1);
    // vector<double> accuVec(10);
    vector<unsigned> finalFeat; 
    // double bestSoFar = defaultRate(data); // too high for small data 61
    // double bestSoFar = 0.5;
    double bestSoFar = kValidationRemoval(features, 200, data);
    double val = 0.0;
    cout << "Default rate is: " << bestSoFar << endl << endl;
    int fToAdd = -1;
    double BestLevel = 0.0;
    for(unsigned i = 1; i < 51; i++){ // search through each feature
        fToAdd = -1;
        BestLevel = 0.0;
        cout << "Level " << i << ' ' << endl;
        for(unsigned j = 1; j < 51; j++){ // start from 1 because feature 0 is ID
            if(features[j-1]){
                cout << "Considering feature " << j << "...\t";
                val = kValidationRemoval(features, j, data);
                cout.precision(5);
                cout << "accuracy is " << val << endl;
                if(val > BestLevel){
                    BestLevel = val;
                    fToAdd = j;
                }
                if(bestSoFar < BestLevel){
                    bestSoFar = BestLevel;
                    // finalFeat.clear();
                    finalFeat = features;
                    finalFeat[j-1] = 0; 
                }
            }
        }

        if(fToAdd > 0){
            cout << "On level " << i << ", removed feature " << fToAdd << endl << endl;
            // accuVec[i-1] = BestLevel;
            features[fToAdd-1]=0;
            
            cout << "\ncurrent features are: ";
            for(unsigned x = 0; x<features.size();x++){
                if(features[x]){cout << ' ' << x+1;}
            }
            cout << endl;

        }
        else { cout << endl;}
    }

    cout << "\nBest Features are:";
    for(unsigned n = 0; n<finalFeat.size(); n++){
        if(finalFeat[n]){
            cout << ' ' << n+1;
        }
    }
    cout << "\nBest Accuracy: " << bestSoFar << endl;
    
}

#endif