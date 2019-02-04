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
    db->saveToFile(DATABASE_FILENAME);

    return 0;
}
