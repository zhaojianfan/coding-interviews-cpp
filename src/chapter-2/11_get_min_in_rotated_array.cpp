#include "solution.h"

/*
 * 11. 旋转数组的最小数字
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。
 * 请返回旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，该数组的最小值为1。
 */

int solution::GetMinInRotatedArray(vector<int>& numbers) {
    int index1 = 0;
    int index2 = numbers.size() - 1;
    int indexMid = index1;

    auto GetMinInOrder = [numbers]() -> int {
        int min = INT32_MAX;
        for (const int num: numbers) {
            if (num < min) {
                min = num;
            }
        }
        return min;
    };

    while (numbers[index1] >= numbers[index2]) {
        // 跳出条件
        if (index2 - index1 == 1) {
            indexMid = index2;
            break;
        }

        indexMid = (index1 + index2) / 2;

        // 若无法比较，则按照顺序查找
        if (numbers[index1] == numbers[index2] && numbers[index1] == numbers[indexMid]) {
            return GetMinInOrder();
        }

        // 迭代中间元素
        if (numbers[index1] <= numbers[indexMid]) {
            index1 = indexMid;
        } else if (numbers[index2] >= numbers[indexMid]) {
            index2 = indexMid;
        }
    }

    return numbers[indexMid];
}
