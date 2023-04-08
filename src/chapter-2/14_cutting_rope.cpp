#include "solution.h"

/*
 * 14-1. 剪绳子-I
 * 给你一根长度为n的绳子，请把绳子剪成整数长度的m段（m、n都是整数，n>1并且m>1），
 * 每段绳子的长度记为k[0],k[1]...k[m-1]。请问k[0]*k[1]*...*k[m-1]可能的
 * 最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时
 * 得到的最大乘积是18。
 */

int solution::CuttingRope_DP(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;

    vector<int> products = {0, 1, 2, 3};
    products.resize(n + 1);

    int maxProduct;
    for (int i = 4; i <= n; ++i) {
        maxProduct = 0;
        for (int j = 1; j <= i / 2; ++j) {
            int product = products[j] * products[i - j];
            if (maxProduct < product) {
                maxProduct = product;
            }
            products[i] = maxProduct;
        }
    }

    maxProduct = products[n];
    return maxProduct;
}


/*
 * 14-2. 剪绳子-II
 * 给你一根长度为n的绳子，请把绳子剪成整数长度的m段（m、n都是整数，n>1并且m>1），
 * 每段绳子的长度记为k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1]
 * 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，
 * 此时得到的最大乘积是18。答案需要取模 e9+7（1000000007，如计算初始结果为：1000000008，请返回 1。
 */

int solution::CuttingRope_GD(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;

    int timesOf3 = n / 3;
    if (n - timesOf3 * 3 == 1) --timesOf3;
    int timesOf2 = (n - timesOf3 * 3) / 2;

    long long result =
            (FastPowerRemainder(3, timesOf3, 1000000007) * FastPowerRemainder(2, timesOf2, 1000000007)) % 1000000007;
    return static_cast<int>(result);
}

long long solution::FastPowerRemainder(int x, int a, int p) {
    long long remainder = 1;
    long long base = x;
    long long exp = a;
    long long divisor = p;

    while (exp > 0) {
        if (exp % 2 == 1) {
            remainder = (remainder * base) % divisor;
        }
        base = (base * base) % divisor;
        exp /= 2;
    }

    return remainder;
}
