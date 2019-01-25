#pragma once
#include <string>
#include "Person.hpp"

using namespace std;

#define EMPLOYEE_MARKER 1

class Employee : public Person {
    public:
        Employee(const string name,
                 const string lastName,
                 const int64_t pesel,
                 const Gender gender,
                 const string address,
                 const int income);

        virtual void show();
        virtual ostream& serialize(ostream& out) const;
        int getIncome() const;
        void setIncome(const int newIncome);

    private:
        int income_;
};
