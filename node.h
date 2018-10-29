#pragma once

#include <string>
#include <memory>

#include "date.h"
#include "comparison.h"

class Node {
public:
    virtual ~Node() {}
    virtual bool Evaluate(const Date &date, const std::string &event) = 0;
};

class EmptyNode final : public Node {
public:
    bool Evaluate(const Date &date, const std::string &event) override final {
        std::cout << "Emnpty Node " << date << " " << event << std::endl;
        return 0;
    }
};

class DateComparisonNode final : public Node {
public:
    DateComparisonNode(const Comparison &comp, const Date &date) :
        comp_(comp), date_(date) {}
    bool Evaluate(const Date &date, const std::string &event) {
        (void)(event);
        switch (comp_) {
        case Comparison::Less:
            return date < date_;
        case Comparison::LessOrEqual:
            return date <= date_;
        case Comparison::Greater:
            return date > date_;
        case Comparison::GreaterOrEqual:
            return date >= date_;
        case Comparison::Equal:
            return date == date_;
        case Comparison::NotEqual:
            return date != date_;
        default:
            return false;
        }
    }
    const Comparison comp_;
    const Date date_;
};

class EventComparisonNode final : public Node {
public:
    EventComparisonNode(const Comparison &comp, const std::string event) :
        comp_(comp), event_(event) {}
    bool Evaluate(const Date &date, const std::string &event) override final {
        (void)(date);
        switch (comp_) {
        case Comparison::Equal:
            return event == event_;
        case Comparison::NotEqual:
            return event != event_;
        default:
            return false;
        }
    }
    const Comparison comp_;
    const std::string event_;
};

class LogicalOperationNode final : public Node {
public:
    LogicalOperationNode(const LogicalOperation &log, std::shared_ptr<Node> left,
                         std::shared_ptr<Node> right) :
        log_(log), left_(left), right_(right) {}

    bool Evaluate(const Date &date, const std::string &event) override final {
        switch (log_) {
        case LogicalOperation::And:
            return left_->Evaluate(date, event) && right_->Evaluate(date, event);
        case LogicalOperation::Or:
            return left_->Evaluate(date, event) || right_->Evaluate(date, event);
        default:
            return false;
        }
    }
    const LogicalOperation &log_;
    std::shared_ptr<Node> left_;
    std::shared_ptr<Node> right_;
};
