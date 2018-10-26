#pragma once

#include <iostream>
#include <map>
#include <deque>
#include <functional>

#include "date.h"

template <class Param>
using Fn = std::function<Param>;

using Events = std::deque<std::string>;
using DateEventsMap = std::map<Date, Events>;

class Database
{
public:
    Database();

    void Add(const Date &date, const std::string &event);

    void Print(std::ostream &stream);

    void RemoveIf();

    void FindIf();

    std::string Last(const Date &date);

private:
    DateEventsMap dateEvents_;
};
