#include "solution.h"

/*
 * 05. 替换空格
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 */

string solution::ReplaceSpace(string s) {
    int numOfSpace = 0;
    const int originalLength = s.size();

    for (const char ch: s) {
        if (ch == ' ') {
            ++numOfSpace;
        }
    }

    const int newLength = originalLength + numOfSpace * 2;
    s.resize(newLength);

    int indexOfOriginal = originalLength - 1;
    int indexOfNew = newLength - 1;

    while (indexOfOriginal != indexOfNew) {
        if (s[indexOfOriginal] != ' ') {
            s[indexOfNew--] = s[indexOfOriginal];
        } else {
            s[indexOfNew--] = '0';
            s[indexOfNew--] = '2';
            s[indexOfNew--] = '%';
        }

        --indexOfOriginal;
    }

    return s;
}
