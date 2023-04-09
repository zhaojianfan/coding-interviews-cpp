#include <iostream>

#include "solution.h"
#include "data_structure.h"

using namespace solution;
using namespace ds;

int main() {
    std::string str = "";
    std::string pattern = "";
    bool res = solution::MatchRegularExpression(str, pattern);
    std::cout << res << std::endl;

    return 0;
}
