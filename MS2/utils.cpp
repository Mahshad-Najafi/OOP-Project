//Name:         Mahshad Najafi Ragheb
//Date :        2021-04-06
//* Citation and Sources:
//Final Project Milestone 2
//Module: utils
//Filename: utils.cpp
//Version 1.1
//Author	Mahshad Najafi Ragheb
//Revision History
//-----------------------------------------------------------
//Date          Reason
//2021-04-06    Modified getInt function with one argument for negative numbers.
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <ctype.h>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
    bool debug = false;  // made global in utils.h
    int getTime() {
        int mins = -1;
        if (debug) {
            sdds::Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;   // needs extraction operator overloaded for Time
                if (!cin) {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
    int getInt(const char* prompt) {
        char input[1000] = "";
        int flag = 1;
        if (prompt != nullptr) {
            cout << prompt;
        }
        while (flag != 0) {
            flag = 0;
            cin.getline(input, 1000);  
            if (!isdigit(input[0]) && input[0] != '-') {  //condition for negative numbers added 
                cout << "Bad integer value, try again: ";
                flag = 1;
            }
            else {
                for (unsigned i = 1; i < strlen(input); i++) {
                    if (!isdigit(input[i]) && input[i] != '\n') {
                        cout << "Enter only an integer, try again: ";
                        flag = 1;
                        break;
                    }
                }
            }
        }
        return stoi(input);
    }
    int getInt(
        int min,
        int max,
        const char* prompt,
        const char* errorMessage,
        bool showRangeAtError)
    {
        int input = getInt(prompt);
        while (input > max || input < min)
        {
            if (errorMessage)
                cout << errorMessage;
            if (showRangeAtError)
                cout << "[" << min << " <= value <= " << max << "]: ";

            input = getInt("");
        }
        return input;
    }
    char* getcstr(const char* prompt, std::istream& istr, char delimiter) {
        if (prompt != nullptr)
            cout << prompt;

        char c;
        string input;
        char* output;
        do {
            c = getchar();
            input += c;
        } while (c != delimiter);
        output = new char[input.length() + 1];

        strcpy(output, input.c_str());
        output[strlen(output) - 1] = '\0';
        return output;
    }
}