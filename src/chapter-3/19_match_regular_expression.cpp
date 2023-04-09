#include "solution.h"

/*
 * 19. 正则表达式匹配
 * 请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
 * 而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。
 * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
 */

// NOT PASS
bool solution::MatchRegularExpression(string s, string p) {
    if (s.empty() && p.empty()) {
        return true;
    }

    if (!s.empty() && p.empty()) {
        return false;
    }

    if (p[1] == '*') {
        if (p[0] == s[0] || (p[0] == '.' && !s.empty())) {
            // 完成匹配，进入下一状态
            bool res1 = MatchRegularExpression(CutString(s, 1), CutString(p, 2));
            // 保持当前状态
            bool res2 = MatchRegularExpression(CutString(s, 1), p);
            // 忽略*，进入下一状态
            bool res3 = MatchRegularExpression(s, CutString(p, 2));

            return res1 || res2 || res3;
        } else {
            // 忽略*，进入下一状态
            bool res = MatchRegularExpression(s, CutString(p, 2));
            return res;
        }
    }

    if (p[0] == s[0] || (p[0] == '.' && !s.empty())) {
        // 完成匹配，进入下一状态
        bool res = MatchRegularExpression(CutString(s, 1), CutString(p, 1));
        return res;
    }

    return false;
}

string solution::CutString(string& s, int n) {
    string newStr;
    return newStr.assign(s, n, s.length() - n);
}
