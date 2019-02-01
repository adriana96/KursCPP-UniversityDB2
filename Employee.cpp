#include "Employee.hpp"

using namespace std;

Employee::Employee(const string name,
                   const string lastName,
                   const int64_t pesel,
                   const Gender gender,
                   const string address,
                   const int income)
    : Person(name, lastName, pesel, gender, address)
    , income_(income) {}

int Employee::getIncome() const {
    return income_;
}

void Employee::setIncome(const int newIncome) {
    income_ = newIncome;
}

void Employee::show() {
    cout << name_ << " " << lastName_ << " " << pesel_ << " "
         << (gender_ ? "male " : "female ") << address_ << " "
         << income_ << endl;
}
