#include <vector>
#include <string>
#include <algorithm>
#include "Student.hpp"
#include "Employee.hpp"
#include "PeselValidation.hpp"

using namespace std;
using Persons = vector<Person*>;

class Database {
    public:
        void addItem(Person * person);
        void removeByPESEL(const int64_t pesel);
        void modifyIncome(const uint newIncome, const int64_t pesel);
        void modifyAddress(const string newAddress, const int64_t pesel);
        void sortByLastname();
        void sortByPESEL();
        void sortByIncome();
        void searchByLastname(const string lastname);
        void searchByPESEL(const int64_t pesel);
        void showAll();
        bool validatePESEL(int64_t pesel);
        bool loadFromFile(const string filename);
        bool saveToFile(const string filename);

    private:
        Persons db_;
};
