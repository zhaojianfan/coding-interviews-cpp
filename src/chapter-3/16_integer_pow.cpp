#include "solution.h"

/*
 * 16. 数值的整数次方
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。不得使用库函数，同时不需要考虑大数问题。
 */

double solution::MyPow(double x, int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return x;
    }

    bool isMinus = false;
    if (n < 0) {
        n = abs(n);
        isMinus = true;
    }

    double result = MyPow(x, n / 2);
    result *= result;
    if (n % 2 == 1) {
        result *= x;
    }

    if (isMinus) {
        return 1 / result;
    } else {
        return result;
    }
}
