#include "solution.h"

/*
 * 03. 数组中重复的数字
 * 在一个长度为n的数组 nums 里的所有数字都在0～n-1的范围内。
 * 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
 */

int solution::FindRepeatNumber(vector<int>& nums) {
    const int length = nums.size();

    if (length == 0) {
        return false;
    }

    for (int i = 0; i < length; ++i) {
        if (nums[i] < 0 || nums[i] > length - 1) {
            return false;
        }
    }

    for (int i = 0; i < length; ++i) {
        while (nums[i] != i) {
            int& value = nums[i];

            if (nums[value] == value) {
                return value;
            }

            std::swap(value, nums[value]);
        }
    }

    return -1;
}
