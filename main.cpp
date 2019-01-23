#include <iostream>

using namespace std;

#define MENU_SHOW			1
#define MENU_NEW_STUDENT	2
#define MENU_NEW_EMPLOYEE	3
#define MENU_SEARCH_NAME	4
#define MENU_SEARCH_PESEL	5
#define MENU_REMOVE_PESEL	6
#define MENU_MODIFY_PESEL	7
#define MENU_SORT_SALARY	8
#define MENU_SORT_PESEL		9
#define MENU_SORT_NAME		10
#define MENU_EXIT			11

void menuShow() {
    cout << endl << "Program option:" << endl;
    cout << "1. Show students list" << endl;
    cout << "2. Add new student" << endl;
	cout << "3. Add new employee" << endl;
    cout << "4. Search by last name" << endl;
    cout << "5. Search by PESEL" << endl;
    cout << "6. Remove by PESEL" << endl ;
    cout << "7. Modify emplyee by PESEL" << endl;
    cout << "8. Sort by salary" << endl;
    cout << "9. Sort by PESEL" << endl;
	cout << "10. Sort by last name" << endl;
	cout << "11. Exit" << endl;
}

int main() {
    int option;

    // Clear terminal
    cout << "\033[2J\033[1;1H";

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
    } while (option != MENU_EXIT);
    
    return 0;
}
