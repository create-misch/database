#pragma once

enum class Comparison {
    Unknown,
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
    End
};

enum class LogicalOperation {
    Or,
    And
};
