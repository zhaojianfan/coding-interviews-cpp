#include "solution.h"

/*
 * 21. 调整数组顺序使奇数位于偶数前面
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
 */

vector<int> solution::Reorder(vector<int>& nums) {
    if (nums.empty()) {
        return nums;
    }

    auto pBegin = nums.begin();
    auto pEnd = --nums.end();
    auto IsOdd = [](int num) -> bool {
        return num % 2 == 1;
    };

    while (pBegin < pEnd) {
        while (pBegin < pEnd && IsOdd(*pBegin)) {
            pBegin++;
        }

        while (pBegin < pEnd && !IsOdd(*pEnd)) {
            pEnd--;
        }

        if (pBegin < pEnd) {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }

    return nums;
}
