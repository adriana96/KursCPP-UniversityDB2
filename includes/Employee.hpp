#pragma once
#include <string>
#include "Person.hpp"

using namespace std;

class Employee : public Person {
    public:
        Employee(const string name,
                 const string lastName,
                 const int64_t pesel,
                 const Gender gender,
                 const string address,
                 const int income);

        virtual void show();
        int getIncome() const;
        void setIncome(const int newIncome);

    private:
        int income_;
};
