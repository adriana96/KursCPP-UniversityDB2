#pragma once
#include "Person.hpp"

using namespace std;

class Student : public Person {
    public:
        Student(const string name,
                const string lastName,
                const int64_t pesel,
                const Gender gender,
                const string address,
                const int32_t index);

        virtual void show();
        int32_t getIndex() const;

    private:
        int32_t index_;
};
