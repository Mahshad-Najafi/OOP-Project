//Name:         Mahshad Najafi Ragheb
//Date :        2021-04-06
//* Citation and Sources:
//Final Project Milestone 2
//Module: Menu
//Filename: Menu.h
//Version 1.0
//Author	Mahshad Najafi Ragheb
//Revision History
//-----------------------------------------------------------
//No Revision
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------*/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds {
    class Menu {
        char* m_text = nullptr; // holds the menu content dynamically
        int m_noOfSel = 0;  // holds the number of options displayed in menu content
        void display()const;
    public:
        Menu(const char* MenuContent = nullptr, int NoOfSelections = 0); // MN initialzed the variables
        virtual ~Menu();
        int& operator>>(int& Selection);
        // add safe copying logic
        Menu(const Menu&);
        Menu& operator=(const Menu&) = delete;
    };
}
#endif // !SDDS_MENU_H
