//
// Created by Mirna Dolunay on 10/30/20.
//

#include "functions.h"
//
// Created on 2019-04-17.
//

#include "functions.h"
#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <string>
#include "functions.h"
using namespace std;

void printUserChoice() {
    cout << "Please Choose a Letter From Below: " << endl;
    cout << "a. Read responses from a file\n" << "b. Play Magic Eight Ball\n" << "c. Sort by responses\n";
    cout << "d. Sort by and categories\n" << "e. Write responses to a file\n" << "f. Exit\n";
}

void printResponses(string responses [ ], string categories [ ], int size) {
    for(int i = 0; i < size; i++) {
        cout << i <<": " <<responses[i]<<" " << categories[i];
        cout <<  endl;
    }
}

// This function will switch the values of two strings.
void switchStrings(string &firstString, string &secondString) {
    string temp;
    temp = firstString;
    firstString = secondString;
    secondString = temp;
}

// This function will sort two parallel string arrays alphabetically based on the first one
void sortParallelArrays(string firstArray [ ], string secondArray[ ], int size) {
    for (int i = 0; i < (size - 1); i++) {
        for (int j = i + 1; j < size; j++) {
            if (firstArray[i] > firstArray[j]) {
                switchStrings(firstArray[i], firstArray[j]);
                switchStrings(secondArray[i], secondArray[j]);
            }
        }
    }
}


void readResponses(ifstream &inFile, string responses [ ], string categories [ ], int &size ) {
    int counter = 0;
    int arr1 = 0;
    int arr2 = 0;
    inFile.open("Responses.txt");
    if (!inFile.is_open()) {
        cout << "Could not open file Responses.txt" << endl;
        return;
    }
    while (!inFile.eof()) {
        string inputString;
        getline(inFile, inputString);
        if (counter % 2 == 0) {
            responses[arr1] = inputString;
            cout<< counter/2<<":  " << inputString ;
            arr1++;
        } else {
            categories[arr2] = inputString;
            cout << " : " << inputString << endl;
            arr2++;
        }
        counter++;
    }
    size = arr1;
    inFile.close();
}

int playMagicEightBall(string responses [ ], string categories [ ], int size, string &userQ) {
    int randomValue;
    string inputString;
    fstream inFile;

    randomValue = (rand() / 100) % 20;
    cout << "Please enter a question to predict:\n\n";
    cin.ignore();
    getline(cin, userQ);
    cout << "Response: " << responses[randomValue] << "    " << categories[randomValue]<<  endl;
    return randomValue;
}

// This function wil sort the two arrays alphabetically by responses.
void sortByResponses(string responses [ ], string categories [ ] , int size) {
    sortParallelArrays(responses, categories, size);
    cout << endl << endl;
}

// This function wil sort the two arrays alphabetically by category.
void sortByCategories(string responses [ ], string categories [ ], int size ) {
    sortParallelArrays(categories, responses, size);
    cout << endl << endl;
}


void writeToFile(ofstream &outputFile, string userData[], string categories [ ], int size){
    string userRes,userCata;
    int i;
    ofstream outfile;
    outputFile.open("Responses.txt", ios::app);
    cout << "write your responses with the category\n";
    cin.ignore();
    getline(cin, userRes);
    userData[i] = userRes;
    //categories[i] = userCata;
    outputFile << endl << userData[i];

    outputFile.close();
}
