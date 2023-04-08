#include "solution.h"

#include <cmath>

/*
 * 17. 打印从1到最大的n位数
 * 输入数字n，按顺序打印出从1到最大的n位十进制数。比如输入3，则打印出1、2、3 一直到最大的3位数999。
 */

vector<int> solution::PrintNumbers(int n) {
    int maxNum = pow(10, n);
    vector<int> result;

    for (int i = 1; i < maxNum; ++i) {
        result.push_back(i);
    }

    return result;
}
