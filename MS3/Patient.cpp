//Name:         Mahshad Najafi Ragheb
//Date :        2021-04-07
//* Citation and Sources:
//Final Project Milestone 3
//Module: Patient
//Filename: Patient.cpp
//Version 1.0
//Author	Mahshad Najafi Ragheb
//Revision History
//-----------------------------------------------------------
//No Revision
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
#include <string>
#include <iostream>
#include <fstream>

namespace sdds {
	Patient::Patient(int ticketNo, bool flag){
		m_ticket = Ticket(ticketNo);
		IOFlag = flag;
	}
	Patient::~Patient() {
		delete[] m_name;
	}
	bool Patient::operator==(char singleChar) const {
		return (type() == singleChar) ? true : false;
	}
	bool Patient::operator==(const Patient& P) const {
		return (type() == P.type()) ? true : false;
	}
	void Patient::setArrivalTime(){
		m_ticket.setTime(Time((unsigned int)getTime()));
	}
	Patient::operator Time() const {
		return Time(m_ticket);
	}
	int Patient::number() const {
		return m_ticket.number();
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr)const {
		ostr << type() << ',' << m_name << ',' << m_OHIP << ',';
		m_ticket.csvWrite(ostr);
		return ostr;
	}
	std::istream& Patient::csvRead(std::istream& istr) {
		std::string s;
		if (istr) {
			getline(istr, s, ',');
			if (m_name != nullptr)
				delete[] m_name;
			m_name = new char[s.length() + 1];
			strcpy(m_name, s.c_str());		//copy string to cstring
		}
		if (istr) {
			std::getline(istr, s, ',');
			m_OHIP = stoi(s);		// string to integer
			m_ticket.csvRead(istr);
		}
		return istr;
	}
	std::ostream& Patient::write(std::ostream& ostr)const {
		ostr << m_ticket << std::endl;
		char* name = nullptr;
		name = new char[strlen(m_name) + 1];
		strcpy(name, m_name);
		if (strlen(name) > 26)
			name[25] = '\0';
		ostr << name << ", OHIP: " << m_OHIP;
		delete[] name;
		return ostr;
	}
	std::istream& Patient::read(std::istream& istr) {
		std::cout << "Name: ";
		std::string name;
		std::getline(istr, name);
		m_name = new char[name.length() + 1];
		strcpy(m_name, name.c_str());
		std::cout << "OHIP:";
		m_OHIP = getInt(100000000, 999999999, "", "Invalid OHIP Number, ", true);
		return istr;
	}
}