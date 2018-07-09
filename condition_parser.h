#pragma once

#include <memory>
#include <iostream>

class Node;

using namespace std;

shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();
