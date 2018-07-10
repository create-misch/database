#pragma once

#include <iostream>

#include "token.h"

class Date;
class Event;

class Node {
public:
    Node();

    virtual int Evaluate(const Date &date, const std::string &event) = 0;
};

class EmptyNode final : public Node {
public:
    int Evaluate(const Date &date, const std::__1::string &event) {
        (void)date;
        (void)event;
        return 0;
    }
};

class DateComparisonNode final : public Node {
public:
    DateComparisonNode(const Comparison c, const Date &date) {
        (void)c;
        (void)date;
    }
    int Evaluate(const Date &date, const std::__1::string &event) {
        (void)date;
        (void)event;
        return 0;
    }
};

class EventComparisonNode final : public Node {
public:
    EventComparisonNode(const Comparison c, const std::string &event) {}
    int Evaluate(const Date &date, const std::__1::string &event) {
        (void)date;
        (void)event;
        return 0;
    }
};

class LogicalOperationNode final : public Node {
public:
    LogicalOperationNode(const LogicalOperation op, std::shared_ptr<Node> lhs, std::shared_ptr<Node> rhs) {}
    int Evaluate(const Date &date, const std::__1::string &event) {
        (void)date;
        (void)event;
        return 0;
    }
};
