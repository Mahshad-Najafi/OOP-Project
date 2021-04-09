//Name:         Mahshad Najafi Ragheb
//Date :        2021-04-07
//* Citation and Sources:
//Final Project Milestone 3
//Module: IOAbles
//Filename: IOAbles.cpp
//Version 1.0
//Author	Mahshad Najafi Ragheb
//Revision History
//-----------------------------------------------------------
//No Revision
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------*/
#include "IOAble.h"

using namespace std;
namespace sdds {
	std::ostream& IOAble::csvWrite(std::ostream& OS) const {
		return OS;
	}
	std::istream& IOAble::csvRead(std::istream& IS) {
		return IS;
	}
	std::ostream& IOAble::write(std::ostream& OS) const {
		return OS;
	}
	std::istream& IOAble::read(std::istream& IS) {
		return IS;
	}
	IOAble::~IOAble() {
	}
	std::ostream& operator<<(std::ostream& OS, const IOAble& S) {
		return S.write(OS);
	}
	std::istream& operator>>(std::istream& IS, IOAble& S) {
		return S.read(IS);
	}
}