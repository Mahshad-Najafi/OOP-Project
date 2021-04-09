//Name:         Mahshad Najafi Ragheb
//Date :        2021-04-07
//* Citation and Sources:
//Final Project Milestone 3
//Module: IOAbles
//Filename: IOAbles.h
//Version 1.0
//Author	Mahshad Najafi Ragheb
//Revision History
//-----------------------------------------------------------
//No Revision
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------*/
#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>
#include <string>
#include <cstring>

namespace sdds {
	class IOAble {
	public:
		virtual std::ostream& csvWrite(std::ostream& OS) const;
		virtual std::istream& csvRead(std::istream& IS);
		virtual std::ostream& write(std::ostream& OS) const;
		virtual std::istream& read(std::istream& IS);
		virtual ~IOAble();
	};
	std::ostream& operator<<(std::ostream& OS, const IOAble& S);
	std::istream& operator>>(std::istream& IS, IOAble& S);
}
#endif // !SDDS_IOABLE_H

