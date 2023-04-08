#include "solution.h"

/*
 * 04. 二维数组中的查找
 * 在一个 n * m 的二维数组中，每一行都按照从左到右非递减的顺序排序，
 * 每一列都按照从上到下非递减的顺序排序。请完成一个高效的函数，
 * 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */

bool solution::FindNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    int row = 0;
    int col = matrix[0].size() - 1;

    while (row <= matrix.size() - 1 && col >= 0) {
        const int value = matrix[row][col];

        if (value == target) {
            return true;
        } else if (value > target) {
            --col;
        } else {
            ++row;
        }
    }

    return false;
}
