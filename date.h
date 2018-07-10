#pragma once

#include <iostream>
#include <cstdint>

class Date
{
public:
    Date();
    Date(const int year, const int month, const int day);

    Date(std::string &&year, std::string &&month, std::string &&day);

    friend bool operator <(const Date &lhs, const Date &rhs);

    friend bool operator ==(const Date &lhs, const Date &rhs);

    friend std::iostream &operator <<(std::iostream &stream, const Date &rhs);

private:
    uint8_t day_;
    uint8_t month_;
    uint16_t year_;
};

bool operator <(const Date &lhs, const Date &rhs);
bool operator ==(const Date &lhs, const Date &rhs);

std::istream &operator << (std::istream &stream, const Date &rhs);

Date ParseDate(std::istream &is);

void TestParseDate();
