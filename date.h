#pragma once

#include <iostream>
#include <cstdint>

class Date {
public:
    Date();
    Date(const int year, const int month, const int day);

    Date(const std::string &year, const std::string &month, const std::string &day);

    friend bool operator <(const Date &lhs, const Date &rhs);
    friend bool operator ==(const Date &lhs, const Date &rhs);
    friend std::ostream &operator <<(std::ostream &stream, const Date &rhs);

private:
    int day_ = 0;
    int month_ = 0;
    int year_ = 0;
};

bool operator <(const Date &lhs, const Date &rhs);
bool operator ==(const Date &lhs, const Date &rhs);

std::ostream &operator << (std::ostream &stream, const Date &rhs);

Date ParseDate(std::istream &is);

void TestParseDate();
