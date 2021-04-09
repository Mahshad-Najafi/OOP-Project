//Name:         Mahshad Najafi Ragheb
//Date :        2021-04-07
//* Citation and Sources:
//Final Project Milestone 3
//Module: Patient
//Filename: Patient.h
//Version 1.0
//Author	Mahshad Najafi Ragheb
//Revision History
//-----------------------------------------------------------
//No Revision
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------*/
#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include <string>
#include "IOAble.h"
#include "Ticket.h"
#include "utils.h"

namespace sdds {
	class Patient:public IOAble {
		char* m_name = nullptr; //A character pointer variable to hold the name of the patient in a Cstring dynamically.
		unsigned m_OHIP; //exactly 9 digits
		Ticket m_ticket;
		bool IOFlag = true;
	public:
		Patient(int ticketNo = 0, bool flag = false);
		Patient(const Patient&) = delete;		//A patient cannot be copied to another patient
		Patient& operator=(const Patient&) = delete;		//A patient cannot be assigned to another patient
		~Patient();
		virtual char type() const {
			return '*';
		}	//will be modified in upcoming MS
		bool fileIO() const {
			return IOFlag;
		}
		void fileIO(bool iofile) {
			IOFlag = iofile;
		}
		bool operator==(char) const;
		bool operator==(const Patient&) const;
		void setArrivalTime();
		operator Time() const;
		int number() const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
}

#endif // !SDDS_PATIENT_H
