#include "solution.h"

/*
 * 10-1. 斐波那契数列
 * 写一个函数，输入 n ，求斐波那契 (Fibonacci) 数列的第 n 项（即 F(N)）。
 */

int solution::GetFibonacciItem(int n) {
    constexpr int result[2] = {0, 1};
    if (n < 2) {
        return result[n];
    }

    int fibN = 0;
    int fibNMinusOne = 1;
    int fibNMinusTwo = 0;

    for (int i = 2; i <= n; ++i) {
        fibN = (fibNMinusOne + fibNMinusTwo) % 1000000007;
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }

    return fibN;
}

/*
 * 10-2. 青蛙跳台阶问题
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * 答案需要取模1e9+7(1000000007)，如计算初始结果为：1000000008，请返回1。
 */

int solution::NumWays(int n) {
    constexpr int result[2] = {1, 1};
    if (n < 2) {
        return result[n];
    }

    int fibN = 0;
    int fibNMinusOne = 1;
    int fibNMinusTwo = 1;

    for (int i = 2; i <= n; ++i) {
        fibN = (fibNMinusOne + fibNMinusTwo) % 1000000007;
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }

    return fibN;
}
