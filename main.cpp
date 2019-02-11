#include <iostream>
#include <cassert>
#include "DataBase.hpp"

using namespace std;

#define DATABASE_FILENAME "db.dat"

int main() {
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

    Database* db = new Database();
    db->loadFromFile(DATABASE_FILENAME);

    Student* s1 = new Student("Jan", "Kowalski", std::stoll("04222978907"), Gender::Male, "addr1", 161234);
    Student* s2 = new Student("Janina", "Kowalska", std::stoll("02221200120"), Gender::Female, "addr2", 161235);
    Student* s3 = new Student("Grazyna", "Kowalska", std::stoll("02221200140"), Gender::Female, "addr3", 161236);
    Student* s4 = new Student("Sabina", "Kowalska", std::stoll("02221200160"), Gender::Female, "addr4", 161237);
    Employee* e1 = new Employee("Adam", "Nowak", std::stoll("89082013830"), Gender::Male, "addr5", 12000);
    Employee* e2 = new Employee("Ewa", "Nowak", std::stoll("89082013820"), Gender::Female, "addr6", 3500);

    if (!db->searchByPESEL(s1->getPESEL())) db->addItem(s1);
    if (!db->searchByPESEL(s2->getPESEL())) db->addItem(s2);
    if (!db->searchByPESEL(s3->getPESEL())) db->addItem(s3);
    if (!db->searchByPESEL(s4->getPESEL())) db->addItem(s4);
    if (!db->searchByPESEL(e1->getPESEL())) db->addItem(e1);
    if (!db->searchByPESEL(e2->getPESEL())) db->addItem(e2);

    cout << "===== Show all =====" << endl;
    db->showAll();

    cout << endl << "===== Search function test =====" << endl;
    db->searchByPESEL(89082013830)->show();
    db->searchByLastname("Nowak")->show();

    cout << endl << "===== Sort by PESEL =====" << endl;
    db->sortByPESEL();
    db->showAll();

    cout << endl << "===== Sort by Last name =====" << endl;
    db->sortByLastname();
    db->showAll();

    cout << endl << "===== Sort by Income =====" << endl;
    db->sortByIncome();
    db->showAll();

    cout << endl << "===== Modify function test =====" << endl;
    db->modifyIncome(e2->getIncome()+1, e2->getPESEL());
    db->modifyAddress("addr11", s1->getPESEL());
    db->showAll();

    db->saveToFile(DATABASE_FILENAME);

    return 0;
}
