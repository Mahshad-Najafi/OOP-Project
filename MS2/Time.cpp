//Name:         Mahshad Najafi Ragheb
//Date :        2021-04-06
//* Citation and Sources:
//Final Project Milestone 1
//Module: Time
//Filename: Time.cpp
//Version 1.0
//Author	Mahshad Najafi Ragheb
//Revision History
//-----------------------------------------------------------
//No Revision
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------*/
//
#include <iostream>
#include <string>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
    Time& Time::setToNow() {
        m_min = getTime();
        return *this;
    }
    Time::Time(unsigned int min) {
        m_min = min;
    }
    std::ostream& Time::write(std::ostream& ostr) const {
        unsigned hour = 0;
        int min = 0;
        hour = m_min / 60;
        min = m_min % 60;
        ostr.fill('0');
        ostr.width(2);
        ostr << hour << ":";
        ostr.fill('0');
        ostr.width(2);
        ostr << min;
        return ostr;
    }
    std::istream& Time::read(std::istream& istr) {
        string input;
        int hour;
        int min;
        istr >> input;
        unsigned int i = 0, colon = 0;
        while (isdigit(input[i])) {
            i++;
        }
        if (input[i] == ':') {
            colon = i;
            i++;
            while (isdigit(input[i])) {
                i++;
            }
            hour = stoi(input.substr(0, colon));
            min = stoi(input.substr(colon + 1));
            m_min = (hour * 60) + min;
            if (i < input.length())
                istr.setstate(ios::failbit);
        }
        else
            istr.setstate(ios::failbit);


        return istr;
    }
    Time& Time::operator-=(const Time& D) {
        signed _min, d_min;
        _min = (signed)m_min;
        d_min = (signed)D.m_min;
        _min -= d_min;
        while (_min < 0) {
            _min = _min + 24 * 60;
        }
        m_min = _min;
        return *this;
    }
    Time Time::operator-(const Time& D)const {
        signed min = m_min - D.m_min;
        while (min < 0) {
            min = min + 24 * 60;
        }
        return Time((unsigned)min);
    }
    Time& Time::operator+=(const Time& D) {
        m_min += D.m_min;
        return *this;
    }
    Time Time::operator+(const Time& D)const {
        unsigned min = m_min + D.m_min;
        return Time(min);
    }
    Time& Time::operator=(unsigned int val) {
        m_min = val;
        return *this;
    }
    Time& Time::operator *= (unsigned int val) {
        m_min *= val;
        return *this;
    }
    Time& Time::operator /= (unsigned int val) {
        m_min /= val;
        return *this;
    }
    Time Time::operator *(unsigned int val)const {
        unsigned min = m_min * val;
        return Time(min);
    }
    Time Time::operator /(unsigned int val)const {
        unsigned min = m_min / val;
        return Time(min);
    }
    Time::operator unsigned int()const {
        return m_min;
    }
    Time::operator int()const {
        return (int)m_min;
    }
}
std::ostream& sdds::operator<<(std::ostream& ostr, const Time& D) {
    return D.write(ostr);
}
std::istream& sdds::operator>>(std::istream& istr, Time& D) {
    return D.read(istr);
}