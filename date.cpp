#include <tuple>

#include "date.h"

using namespace std;

Date::Date() :
    year_(0),
    month_(0),
    day_(0) {}

Date::Date(const int year, const int month, const int day) :
    year_(static_cast<uint16_t>(year)),
    month_(static_cast<uint8_t>(month)),
    day_(static_cast<uint8_t>(day)) {}

Date::Date(string &&year, string &&month, string &&day) :
    year_(year), month_(month), day_(day) {}

bool operator <(const Date &lhs, const Date &rhs) {
    return tie(lhs.year_, lhs.month_, lhs.day_) <
            tie(rhs.year_, rhs.month_, rhs.day_);
}

bool operator ==(const Date &lhs, const Date &rhs) {
    return tie(lhs.year_, lhs.month_, lhs.day_) ==
            tie(rhs.year_, rhs.month_, rhs.day_);
}

istream &operator <<(istream &stream, const Date &rhs) {
    stream << rhs.year_ << "-" << rhs.month_ << "-" << rhs.day_;
}

Date ParseDate(istream &is) {
    auto year = getline(is, "-");
    auto month = getline(is, "-");
    auto day = getline(is, "-");

    return Date(year, month, day);
}
