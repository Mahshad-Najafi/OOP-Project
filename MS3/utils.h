//Name:         Mahshad Najafi Ragheb
//Student ID :  136115201
//Email :       mnajafi - ragheb@myseneca.ca
//Date :        2021-04-07
//* Citation and Sources:
//Final Project Milestone 3
//Module: utils
//Filename: utils.h
//Version 1.0
//Author	Mahshad Najafi Ragheb
//Revision History
//-----------------------------------------------------------
//No Revision
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------*/

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
    extern bool debug;

    int getTime(); // returns the time of day in minutes
    int getInt(const char* prompt = nullptr);
    int getInt(
        int min,   // minimum acceptable value
        int max,   // maximum acceptable value
        const char* prompt = nullptr,  // User entry prompt
        const char* errorMessage = nullptr, // Invalid value error message
        bool showRangeAtError = true    // display the range if invalud value entered 
    );
    char* getcstr(
        const char* prompt = nullptr,   // User entry prompt
        std::istream& istr = std::cin,  // the Stream to read from
        char delimiter = '\n'    // Delimiter to mark the end of data
    );
}
#endif // !SDDS_UTILS_H_