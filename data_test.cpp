#include "date.h"
#include "test_runner.h"

using namespace std;

void TestParseDate() {
    istringstream is("2017-11-03");

    AssertEqual(Date(2017, 11, 03), ParseDate(is), "test date 2017-11-03");
}

