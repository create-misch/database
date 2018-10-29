#include <algorithm>

#include "database.h"

using namespace std;

Database::Database() {}

void Database::Add(const Date &date, const string &event) {
    auto &events = dateEvents_[date];

    if (events.empty()) {
        events.push_back(event);
        return;
    }

    if (find(begin(events), end(events), event) != end(events)) {
        return;
    }

    events.push_back(event);
}

void Database::Print(ostream &stream) {
    auto printPair = [] (ostream  &stream, const pair<Date, Events> &pair) {
        for (const auto & e : pair.second) {
            stream << pair.first << " " << e << endl;
        }
    };

    for (const auto &pair : dateEvents_) {
        printPair(stream, pair);
    }
}

int Database::RemoveIf(Predicate predicate) {
    if (dateEvents_.size() == 0) return 0;

    auto count(0);
    for (auto &pair : dateEvents_) {
        const auto &date = pair.first;
        auto &events = pair.second;
        if (events.empty())
            continue;

        auto it_remove = std::remove_if(begin(events), end(events), [&] (const std::string event) {
            return predicate(date, event);
        });
        count += distance(it_remove, end(events));

        events.erase(it_remove, end(events));
    }
    return count;
}

string Database::Last(const Date &date) {
    auto it_find = dateEvents_.find(date);
    if (it_find == begin(dateEvents_)) {
        return it_find->second.back();
    }
    if (it_find == end(dateEvents_)) {
        return string("No entries");
    }

    return (--it_find)->second.back();
}

