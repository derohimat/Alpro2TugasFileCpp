//
// Created by Deni Rohimat on 2/22/17.
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
//        scanf("%s", input);
        cin >> input;
        return input;
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
        cin >> i;
        return i;
    }

public:
    void print(string message) {
        cout << message;
    }

public:
    void println(string message) {
        cout << message << "\n";
    }
};


#endif //SAMPLECPP_UTILS_H
