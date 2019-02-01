#pragma once
#include "Person.hpp"

enum PeselError {
  valid_ok          = 0,
  invalid_day       = 1,
  invalid_month     = 2,
  invalid_gender    = 4,
  invalid_checksum  = 8
};

PeselError isPeselValid(int64_t pesel, Gender gender);
bool isYearLeap(int year);
PeselError isDateValid(int64_t pesel);
bool isGenderValid(int64_t pesel, Gender gender);
bool isCheckSumValid(int64_t pesel);
