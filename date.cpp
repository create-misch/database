#include <tuple>

#include "date.h"

using namespace std;

Date::Date() {}

Date::Date(const int year, const int month, const int day) :
    day_(day),
    month_(month),
    year_(year) {}

Date::Date(const string &year, const string &month, const string &day) :
    day_(stoi(day)), month_(stoi(month)), year_(stoi(year))  {}

bool operator <(const Date &lhs, const Date &rhs) {
    return tie(lhs.year_, lhs.month_, lhs.day_) <
            tie(rhs.year_, rhs.month_, rhs.day_);
}

bool operator ==(const Date &lhs, const Date &rhs) {
    return tie(lhs.year_, lhs.month_, lhs.day_) ==
            tie(rhs.year_, rhs.month_, rhs.day_);
}

ostream &operator <<(ostream &stream, const Date &rhs) {
    stream << rhs.year_ << "-" << rhs.month_ << "-" << rhs.day_;
    return stream;
}

Date ParseDate(istream &is) {
    int  year, month, day;
    is >> year >> month >> day;
    return Date(year, abs(month), abs(day));
}
