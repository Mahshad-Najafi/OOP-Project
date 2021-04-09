//Name:         Mahshad Najafi Ragheb
//Date :        2021-04-06
//* Citation and Sources:
//Final Project Milestone 2
//Module: ms2Tester
//Filename: ms2Tester.cpp
//Version 2.0
//Author	Mahshad Najafi Ragheb
//Revision History
//-----------------------------------------------------------
//Date          Reason
//2021-04-06    Typo correction for functions's names, Box Class name
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------*/

// IOAble Tester:
// Version: 1.0
// Date: 2021-3-16
// Author: Fardad Soleimanloo
// Description:
// This file tests the IOAble Module of your project
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "Menu.h"
#include "IOAble.h"
using namespace std;
using namespace sdds;
class Box :public IOAble {
   int m_hieght, m_width;
public:
   bool csv;
   Box();
   ostream& csvWrite(std::ostream& ostr)const;
   istream& csvRead(std::istream& istr);
   ostream& write(ostream& ostr)const;
   istream& read(istream& istr);
   virtual ~Box();
};
void menuTester(Menu m);
void displayFile(const char* filename);
void IOAbleTester();

int main() {
   Menu m("Tester Options menu:\n1- Option one\n2- Option two\n3- Option three", 3);
   menuTester(m);
   IOAbleTester();
   return 0;
}



void IOAbleTester() {
   cout << "ioable tester ************************************" << endl;
   Box b;
   cout << "getting information of an ioable box from console: " << endl;
   cin >> b;
   cout << "display the ioable box on console: " << endl;
   cout << b << endl;
   b.csv = false;
   ifstream fboxes("boxes.txt");
   if (fboxes) {
      Box* bp;
      ofstream bout("boxesout.txt");
      b.csv = true;
      cout << "saving " << b << " in the output file." << endl;
      bout << b << endl;
      cout << "dynamically allocating a box and holding it in an ioable pointer..." << endl;
      IOAble* iop = bp = new Box();
      cout << "reading dimenstions from file using the ioalbe pointer" << endl;;
      bp->csv = true;
      fboxes >> *iop;
      cout << "dimentions: " << endl;
      cout << *iop << endl;
      bp->csv = false;
      cout << "what it looks like on screen:" << endl << *iop << endl;
      bp->csv = true;
      cout << "now save it in the file..." << endl;
      bout << *iop << endl;
      cout << "reading the next dimenstions from file using the ioable pointer" << endl;;
      fboxes >> *iop;
      cout << "dimentions: " << endl;
      cout << *iop << endl;
      bp->csv = false;
      cout << "what it looks like on screen:" << endl << *iop << endl;
      bp->csv = true;
      cout << "save this one in the output file too..." << endl;
      bout << *iop << endl;
      cout << "close the file and display it..." << endl;
      bout.close();
      displayFile("boxesout.txt");
      cout << "removing the box from memory using the ioable pointer..." << endl;
      delete bp;
      bout.close();
   }
   else {
      cout << "could not find the file \"boxes.txt\"." << endl;
   }
   cout << "content of \"boxesout.txt\" file" << endl;
   displayFile("boxesout.txt");
}



/* box *********************************************/
Box::Box() :m_hieght(0), m_width(0), csv(false) {
   cout << "defaulting box" << endl;
};
ostream& Box::csvWrite(std::ostream& ostr)const {
   return ostr << m_hieght << "," << m_width;
}
istream& Box::csvRead(std::istream& istr) {
   istr >> m_hieght;
   istr.ignore();
   istr >> m_width;
   istr.ignore();
   return istr;
}
ostream& Box::write(ostream& ostr)const {
   if (csv) {
      csvWrite(ostr);
   }
   else {
      int i;
      for (int j = 0; j < m_hieght; j++) {
         for (i = 0; i < m_width * 2; i++, ostr << "*");
         ostr << endl;
      }
   }
   return ostr;
}
istream& Box::read(istream& istr) {
   if (csv) {
       csvRead(istr);
   }
   else {
      cout << "height: ";
      istr >> m_hieght;
      cout << "width: ";
      istr >> m_width;
   }
   return istr;
}
Box::~Box() {
   cout << "box(" << m_hieght << "," << m_width << ") is gone!" << endl;
}
/* menuTester *********************************************/
void menuTester(Menu m) {
   cout << "Menu Tester **************************************" << endl;
   int selection;
   while (m >> selection) {
      switch (selection) {
      case 1:
         cout << "option one selected" << endl << endl;
         break;
      case 2:
         cout << "option two selected" << endl << endl;
         break;
      case 3:
         cout << "option three selected" << endl << endl;
         break;
      default:
         cout << "This will never happen!!!!" << endl;
         break;
      }
   }
   cout << "goodbye!" << endl;
}
/*  displayFile ***************************************/
void displayFile(const char* filename) {
   ifstream file(filename);
   cout << filename << "---------------------" << endl;
   char ch;
   while (file.get(ch) && cout << ch);
   cout << "---------------------------------" << endl;
}

