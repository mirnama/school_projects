#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <string>
#include "functions.h"
using namespace std;

int main() {
    ifstream inFile;
    ofstream outFile;
    int maxSize = 100, size = 0, returnedVal, newSize = 0;
    char userChoice;
    string userResponses[maxSize];
    string userQ;
    string responses[maxSize], categories[maxSize];
    string *ptr1 = responses;
    string *ptr2 = categories;

    srand (0);

    do {
        printUserChoice();
        cin >> userChoice;
        switch (userChoice) {
            case 'a':
            case 'A':
                readResponses(inFile, ptr1, ptr2, size);
                cout << endl;
                break;
            case 'b':
            case 'B':
                returnedVal = playMagicEightBall(responses, categories, size, userQ);
                userResponses [newSize] = userQ;
                newSize++;
                userResponses [newSize] = responses[returnedVal];
                newSize++;
                break;
            case 'c':
            case 'C':
                sortByResponses(ptr1, ptr2, size);
                printResponses(responses, categories, size);
                break;
            case 'd':
            case 'D':
                sortByCategories(ptr1, ptr2, size);
                printResponses(responses, categories, size);
                break;
            case 'e':
            case 'E':
                writeToFile(outFile, userResponses, categories, newSize);
                cout << "Your Answers are in the file Responses.txt" << endl;
                break;
            case 'f':
            case 'F':
                cout << "Thank you!! Please come again." << endl;
                return 0;
            default:
                cout << "Come on. You can't pick that. Please Chose a valid option.\n\n";
        }
    } while (userChoice != 'f');


    return 0;
}
