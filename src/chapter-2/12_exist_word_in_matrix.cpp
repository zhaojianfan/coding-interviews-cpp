#include "solution.h"

/*
 * 12. 矩阵中的路径
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true；否则，返回 false。
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
 * 同一个单元格内的字母不允许被重复使用。
 */

bool solution::ExistWordInMatrix(vector<vector<char>>& board, string word) {
    if (board.empty()) {
        return false;
    }

    const int rows = board.size();
    const int cols = board[0].size();
    int pathLength = 0;

    bool** visited = new bool* [rows];
    for (int i = 0; i < rows; ++i) {
        visited[i] = new bool[cols];
        std::fill(visited[i], visited[i] + cols + 1, false);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (HasPath(board, word, i, j, pathLength, visited)) {
                return true;
            }
        }
    }

    delete[] visited;
    return false;
}

bool solution::HasPath(vector<vector<char>>& board, string word, int row, int col, int& pathLength, bool**& visited) {
    if (pathLength == word.length()) {
        return true;
    }

    bool hasPath = false;

    if ((row >= 0 && row < board.size()) && (col >= 0 && col < board[0].size())
        && board[row][col] == word[pathLength]
        && !visited[row][col]) {
        ++pathLength;
        visited[row][col] = true;

        hasPath = HasPath(board, word, row + 1, col, pathLength, visited) ||
                  HasPath(board, word, row, col + 1, pathLength, visited) ||
                  HasPath(board, word, row - 1, col, pathLength, visited) ||
                  HasPath(board, word, row, col - 1, pathLength, visited);

        if (!hasPath) {
            --pathLength;
            visited[row][col] = false;
        }
    }

    return hasPath;
}
