//Name:         Mahshad Najafi Ragheb
//Date :        2021-04-06
//* Citation and Sources:
//Final Project Milestone 2
//Module: Menu
//Filename: Menu.cpp
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
#include <iostream>
#include <cstring>
#include "utils.h"
#include "Menu.h"

using namespace std;
namespace sdds {
    void Menu::display()const {
        cout << m_text << endl;
        cout << "0- Exit" << endl;
    }
    Menu::Menu(const char* MenuContent, int NoOfSelections) {
        m_text = new char[strlen(MenuContent) + 1];
        strcpy(m_text, MenuContent);
        m_noOfSel = NoOfSelections;
    }
    Menu::~Menu() {
        delete[] m_text;
    }
    int& Menu::operator>>(int& Selection) {
        display();
        return Selection = getInt(0, m_noOfSel, "> ", "Invalid option ", true);
    }
    Menu::Menu(const Menu& M) {
        m_text = new char[strlen(M.m_text) + 1];
        strcpy(m_text, M.m_text);
        m_noOfSel = M.m_noOfSel;
    }
}