#include "PeselValidation.hpp"

PeselError isPeselValid(int64_t pesel, Gender gender) {
    if (!isCheckSumValid(pesel)) return PeselError::invalid_checksum;
    if (!isGenderValid(pesel, gender)) return PeselError::invalid_gender;
    return isDateValid(pesel);
}

bool isYearLeap(int year) {
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
             (year % 400 == 0));
}

PeselError isDateValid(int64_t pesel) {
    int day = pesel / 100000 % 100;
    int month = pesel / 10000000 % 100;
    int year = pesel / 1000000000;
    int century;

    // Divide century information from month variable
    for (century = 0; month > 20; century++) month -= 20;
    switch (century) {
        case 0:
            year += 1900;
            break;
        case 1:
            year += 2000;
            break;
        case 2:
            year += 2100;
            break;
        case 3:
            year += 2200;
            break;
        case 4:
            year += 1800;
            break;
    }

    if (month < 1 || month > 12) return PeselError::invalid_month;

    // Validate day for February
    if (month == 2) {
        if(isYearLeap(year)) {
            if (day > 29) return PeselError::invalid_day;
        } else {
            if (day > 28) return PeselError::invalid_day;
        }
    // Validate day for April, June, September and November
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return PeselError::invalid_day;
    // Validate day for other months
    } else {
        if (day > 31) return PeselError::invalid_day;
    }

    return PeselError::valid_ok;
}

bool isGenderValid(int64_t pesel, Gender gender) {
    Gender pesel_gender = static_cast<Gender> (pesel / 10 % 2);
    return (gender == pesel_gender) ? true : false;
}

bool isCheckSumValid(int64_t pesel) {
    int a = pesel / 10000000000 % 10;
    int b = pesel / 1000000000 % 10;
    int c = pesel / 100000000 % 10;
    int d = pesel / 10000000 % 10;
    int e = pesel / 1000000 % 10;
    int f = pesel / 100000 % 10;
    int g = pesel / 10000 % 10;
    int h = pesel / 1000 % 10;
    int i = pesel / 100 % 10;
    int j = pesel / 10 % 10;
    int k = pesel / 1 % 10;

    int checksum = (9*a + 7*b + 3*c + d + 9*e + 7*f + 3*g + h + 9*i + 7*j) % 10;

    return (checksum == k) ? true : false;
}
