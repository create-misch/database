#include "database.h"
#include "condition_parser.h"
#include "node.h"
#include "test_runner.h"

#include <iostream>
#include <vector>
#include <istream>
#include <stdexcept>

using namespace std;

void TestAll();
void TestParseEvent();

string ParseEvent(istream& is) {
    // Р РµР°Р»РёР·СѓР№С� Рµ СЌС� Сѓ С„СѓРЅРєС†РёСЋ
    string result;
    is >> result;
//    if (is.get() = " ") {
//        char symbol = is.get();
//        while (symbol != "\n") {
//            result.push_back(symbol);
//        }
//    }
//    for (auto it = result.rbegin(); it != result.rend(); it++ )
//        if (*it == " ")
//            result.pop_back();

    return result;
}

int main() {
    TestAll();

    Database db;

    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "Add") {
            const auto date = ParseDate(is);
            const auto event = ParseEvent(is);
            db.Add(date, event);
        } else if (command == "Print") {
            db.Print(cout);
        } /*else if (command == "Del") {
            auto condition = ParseCondition(is);
            auto predicate = [condition](const Date& date, const string& event) {
                return condition->Evaluate(date, event);
            };
            auto count = db.RemoveIf(predicate);
            cout << "Removed " << count << " entries" << endl;
        } else if (command == "Find") {
            auto condition = ParseCondition(is);
            auto predicate = [condition](const Date& date, const string& event) {
                return condition->Evaluate(date, event);
            };

            const auto entries = db.FindIf(predicate);
            for (const auto& entry : entries) {
                cout << entry << endl;
            }
            cout << "Found " << entries.size() << " entries" << endl;
        }*/ else if (command == "Last") {
            try {
                cout << db.Last(ParseDate(is)) << endl;
            } catch (invalid_argument&) {
                cout << "No entries" << endl;
            }
        } else if (command.empty()) {
            continue;
        } else {
            throw logic_error("Unknown command: " + command);
        }
    }

    return 0;
}

void TestParseEvent() {
    {
        istringstream is("event");
        AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
    }
    {
        istringstream is("   sport event ");
        AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");
    }
    {
        istringstream is("  first event  \n  second event");
        vector<string> events;
        events.push_back(ParseEvent(is));
        events.push_back(ParseEvent(is));
        AssertEqual(events, vector<string>{"first event  ", "second event"}, "Parse multiple events");
    }
}

void TestAll() {
    TestRunner tr;
    tr.RunTest(TestParseEvent, "TestParseEvent");
    tr.RunTest(TestParseCondition, "TestParseCondition");
    tr.RunTest(TestParseDate, "TEstParseDate");
}
