#include <vector>
#include <string>
#include "Student.hpp"
#include "Employee.hpp"
#include "PeselValidation.hpp"

using namespace std;
using Persons = vector<Person*>;

class Database {
    public:
        void addItem(Person * person);
        void removeByPESEL(const int64_t pesel);
        void modifyIncome(const int newIncome, const int64_t pesel);
        void modifyAddress(const string & newAddress, const int64_t pesel);
        void sortByLastname();
        void sortByPESEL();
        void sortByIncome();
        Person* searchByLastname(const string & lastname);
        Person* searchByPESEL(const int64_t pesel);
        void showAll();
        bool validatePESEL(int64_t pesel);
        void loadFromFile(const string & filename);
        void saveToFile(const string & filename);

    private:
        Persons db_;
};
