#pragma once
#include "Person.hpp"

using namespace std;

#define STUDENT_MARKER 0

class Student : public Person {
    public:
        Student(const string name,
                const string lastName,
                const int64_t pesel,
                const Gender gender,
                const string address,
                const int32_t index);

        virtual void show() const;
        virtual ofstream& serialize(ofstream& out) const;
        int32_t getIndex() const;

    private:
        int32_t index_;
};
