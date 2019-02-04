#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum Gender {
    Female,
    Male
};

class Person {
    public:
        Person(const string name,
               const string lastName,
               const int64_t pesel,
               const Gender gender,
               const string address);

        void setAddress(const string newAddress);
        int64_t getPESEL() const;
        string getLastName() const;
        virtual void show() const = 0;
        virtual ofstream& serialize(ofstream& out) const = 0;
        virtual ~Person() {};
        friend ofstream& operator<<(ofstream& output, const Person &b);

    protected:
        string name_;
        string lastName_;
        int64_t pesel_;
        Gender gender_;
        string address_;
};
