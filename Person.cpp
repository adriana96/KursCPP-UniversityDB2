#include "Person.hpp"

using namespace std;

Person::Person(const string name,
               const string lastName,
               const int64_t pesel,
               const Gender gender,
               const string address)
    : name_(move(name))
    , lastName_(lastName)
    , pesel_(pesel)
    , gender_(gender)
    , address_(address) {}

void Person::setAddress(const string newAddress) {
    address_ = newAddress;
}

int32_t Person::getPESEL() const {
    return pesel_;
}

string Person::getLastName() const {
    return lastName_;
}
