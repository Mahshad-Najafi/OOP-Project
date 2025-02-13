//Name:         Mahshad Najafi Ragheb
//Date :        2021-04-07
//* Citation and Sources:
//Final Project Milestone 3
//Module: Ticket
//Filename: Ticket.cpp
//Version 1.1
//Author	Mahshad Najafi Ragheb
//Revision History
//-----------------------------------------------------------
//Date             Reason
//2021-04-10       Removed setTime Function(Redundant)
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------*/
#include "Ticket.h"

namespace sdds {
   Ticket::Ticket(int number) {
      m_number = number;
   }
   Ticket::operator Time() const {
      return m_time;
   }
   int Ticket::number() const {
      return m_number;
   }
   void Ticket::resetTime() {
      m_time.setToNow();
   }
   std::ostream& Ticket::csvWrite(std::ostream& ostr) const {
      return ostr << m_number << "," << m_time;
   }
   std::istream& Ticket::csvRead(std::istream& istr) {
      std::string s;
      getline(istr, s, ',');
      m_number = stoi(s);
      istr >> m_time;
      return istr;
   }
   std::ostream& Ticket::write(std::ostream& ostr) const {
      return ostr << "Ticket No: " << m_number << ", Issued at: " << m_time ;
   }
   std::istream& Ticket::read(std::istream& istr) {

      return csvRead(istr);
   }
}
