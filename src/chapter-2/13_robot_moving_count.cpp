#include "solution.h"

/*
 * 13. 机器人的运动范围
 * 地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，
 * 它每次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和大于k的格子。
 */

int solution::MovingCount(int m, int n, int k) {
    if (m <= 0 || n <= 0 || k < 0) {
        return 0;
    }

    bool** visited = new bool* [m];
    for (int i = 0; i < m; ++i) {
        visited[i] = new bool[n];
        std::fill(visited[i], visited[i] + n, false);
    }

    int count = MovingCountCore(m, n, k, 0, 0, visited);
    for (int i = 0; i < m; ++i) {
        delete[] visited[i];
    }
    delete[] visited;

    return count;
}

int solution::MovingCountCore(int m, int n, int k, int row, int col, bool** visited) {
    int count = 0;
    if (IsReached(m, n, k, row, col, visited)) {
        visited[row][col] = true;

        count = 1 + MovingCountCore(m, n, k, row + 1, col, visited)
                + MovingCountCore(m, n, k, row, col + 1, visited)
                + MovingCountCore(m, n, k, row - 1, col, visited)
                + MovingCountCore(m, n, k, row, col - 1, visited);
    }

    return count;
}

bool solution::IsReached(int m, int n, int k, int row, int col, bool** visited) {
    if ((row >= 0 && row < m) && (col >= 0 && col < n)
        && !visited[row][col]
        && GetDigitSum(row) + GetDigitSum(col) <= k) {
        return true;
    } else {
        return false;
    }
}

int solution::GetDigitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
