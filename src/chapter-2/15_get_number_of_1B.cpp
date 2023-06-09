#include "solution.h"

/*
 * 15. 二进制中1的个数
 * 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为'1'的个数（也被称为 汉明重量).）。
 */

int solution::GetNumberOf1B(uint32_t n) {
    int count = 0;

    while (n) {
        ++count;
        n = (n - 1) & n;
    }

    return count;
}
