#include "solution.h"

using std::string;

/*
 * 20. 表示数值的字符串
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 */

bool solution::IsNumber(string s) {
    if (s.empty()) {
        return false;
    }

    // 去除首尾空格
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);

    bool isNumber = ScanInteger(s);

    // 处理小数部分
    if (s[0] == '.') {
        s = CutNumString(s);
        isNumber = ScanUnsignedInteger(s) || isNumber;
    }
    // 处理指数部分
    if (s[0] == 'e' || s[0] == 'E') {
        s = CutNumString(s);
        isNumber = ScanInteger(s) && isNumber;
    }
    // 处理其他情况
    if (!s.empty()) {
        isNumber = false;
    }

    return isNumber;
}

string solution::CutNumString(string& s) {
    string newStr;
    return newStr.assign(s, 1, s.length() - 1);
}

bool solution::ScanUnsignedInteger(string& s) {
    string before = s;
    while (s[0] >= '0' && s[0] <= '9') {
        s = CutNumString(s);
    }
    bool res = s.length() < before.length();
    return res;
}

bool solution::ScanInteger(string& s) {
    if (s[0] == '+' || s[0] == '-') {
        s = CutNumString(s);
    }
    bool res = ScanUnsignedInteger(s);
    return res;
}
