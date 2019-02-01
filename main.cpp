#include <iostream>
#include <cassert>
#include "DataBase.hpp"

using namespace std;

#define MENU_SHOW               1
#define MENU_NEW_STUDENT        2
#define MENU_NEW_EMPLOYEE       3
#define MENU_SEARCH_NAME        4
#define MENU_SEARCH_PESEL       5
#define MENU_REMOVE_PESEL       6
#define MENU_MODIFY_PESEL       7
#define MENU_SORT_SALARY        8
#define MENU_SORT_PESEL         9
#define MENU_SORT_NAME          10
#define MENU_EXIT               11

void menuShow() {
    cout << "Program option:"   << endl;
    cout << MENU_SHOW           << ". Show students list" << endl;
    cout << MENU_NEW_STUDENT    << ". Add new student" << endl;
    cout << MENU_NEW_EMPLOYEE   << ". Add new employee" << endl;
    cout << MENU_SEARCH_NAME    << ". Search by last name" << endl;
    cout << MENU_SEARCH_PESEL   << ". Search by PESEL" << endl;
    cout << MENU_REMOVE_PESEL   << ". Remove by PESEL" << endl ;
    cout << MENU_MODIFY_PESEL   << ". Modify emplyee by PESEL" << endl;
    cout << MENU_SORT_SALARY    << ". Sort by salary" << endl;
    cout << MENU_SORT_PESEL     << ". Sort by PESEL" << endl;
    cout << MENU_SORT_NAME      << ". Sort by last name" << endl;
    cout << MENU_EXIT           << ". Exit" << endl;
}

int main() {
    int option;

    // Clear terminal
    cout << "\033[2J\033[1;1H";

    // Assert section
    assert(isPeselValid(std::stoll("12345678903"), Gender::Female) == PeselError::invalid_month);
    assert(isPeselValid(std::stoll("12325678901"), Gender::Female) == PeselError::invalid_day);
    assert(isPeselValid(std::stoll("03222978900"), Gender::Female) == PeselError::invalid_day);
    assert(isPeselValid(std::stoll("04222978914"), Gender::Female) == PeselError::invalid_gender);
    assert(isPeselValid(std::stoll("04222978907"), Gender::Male) == PeselError::invalid_gender);
    assert(isPeselValid(std::stoll("04222978901"), Gender::Female) == PeselError::invalid_checksum);
    assert(isPeselValid(std::stoll("04222978907"), Gender::Female) == PeselError::valid_ok);

    do {
        menuShow();
        cin >> option;

        switch (option) {
            case MENU_SHOW :
                cout << "Show students list" << endl;
                break;
            case MENU_NEW_STUDENT :
                cout << "Add new student" << endl;
                break;
            case MENU_NEW_EMPLOYEE :
                cout << "Add new employee" << endl;
                break;
            case MENU_SEARCH_NAME :
                cout << "Search by last name" << endl;
                break;
            case MENU_SEARCH_PESEL :
                cout << "Search by PESEL" << endl;
                break;
            case MENU_REMOVE_PESEL :
                cout << "Remove by PESEL" << endl ;
                break;
            case MENU_MODIFY_PESEL :
                cout << "Modify emplyee by PESEL" << endl;
                break;
            case MENU_SORT_SALARY :
                cout << "Sort by salary" << endl;
                break;
            case MENU_SORT_PESEL :
                cout << "Sort by PESEL" << endl;
                break;
            case MENU_SORT_NAME :
                cout << "Sort by last name" << endl;
                break;
            case MENU_EXIT :
                cout << "Exit (save to file)" << endl;
                break;
            default :
                cout << "Unknown option " << option << "!" << endl;
                break;
        }

        cout << endl;
    } while (option != MENU_EXIT);

    return 0;
}
