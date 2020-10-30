//
// Created  on 2019-04-17.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <fstream>
using namespace std;
void printUserChoice();
void printResponses(string responses [], string categories [], int size);
void switchStrings(string &firstString, string &secondString);
void sortParallelArrays(string firstArray [], string secondArray[], int size);
void readResponses(ifstream &infile, string responses [], string categories[ ], int &size);
int playMagicEightBall(string responses [ ], string categories [], int size, string &userQ );
void sortByResponses(string responses [ ], string categories[] , int size);
void sortByCategories(string responses [ ], string categories [], int size );
void writeToFile(ofstream &, string userData[],string categories [], int size);



#endif //FUNCTIONS_H
