//
// Created by Deni Rohimat on 2/21/17.
//

#ifndef SAMPLECPP_UTILS_H
#define SAMPLECPP_UTILS_H

#include <utility>
#include <string>
#include <iostream>

using namespace std;

class Utils {
public:
    char *inputChar(string message) {
        char *input;

        cout << message;
        scanf("%s", input);
        return input;
    }

public:
    void print(string message) {
        cout << message;
    }

public:
    string inputString(string message) {
        string input;

        cout << message;
        getline(cin, input);
        return input;
    }

public:
    int inputInt(string message) {
        int i;

        cout << message;
        scanf("%d", i);
        return i;
    }
};


#endif //SAMPLECPP_UTILS_H
