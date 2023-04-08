#pragma once

#include <vector>
#include <string>
#include <stack>

#include "data_structure.h"

using namespace ds;
using std::vector;
using std::stack;
using std::string;

namespace solution {
// Question 3
int FindRepeatNumber(vector<int>& nums);

// Question 4
bool FindNumberIn2DArray(vector<vector<int>>& matrix, int target);

// Question 5
string ReplaceSpace(string s);

// Question 6
vector<int> ReversePrint(ListNode* head);

// Question 7
TreeNode* BuildTree(vector<int>& preOrder, vector<int>& inOrder);

TreeNode* ConstructCore(vector<int>& preOrder, vector<int>& inOrder);

// Question 8
TreeNode* GetNext(TreeNode* pNode);

// Question 9
class CQueue {
public:
    CQueue() = default;

    void AppendTail(int value);

    int DeleteHead();

private:
    stack<int> inputStack;
    stack<int> outputStack;
};

// Question 10
int GetFibonacciItem(int n);

int NumWays(int n);

// Question 11
int GetMinInRotatedArray(vector<int>& numbers);

// Question 12
bool ExistWordInMatrix(vector<vector<char>>& board, string word);

bool HasPath(vector<vector<char>>& board, string word, int row, int col, int& pathLength, bool**& visited);

// Question 13
int MovingCount(int m, int n, int k);

int MovingCountCore(int m, int n, int k, int row, int col, bool** visited);

bool IsReached(int m, int n, int k, int row, int col, bool** visited);

int GetDigitSum(int num);

// Question 14
int CuttingRope_DP(int n);

int CuttingRope_GD(int n);

long long FastPowerRemainder(int x, int a, int p);

// Question 15
int GetNumberOf1B(uint32_t n);

// Question 16
double MyPow(double x, int n);

// Question 17
vector<int> PrintNumbers(int n);

// Question 18
ListNode* DeleteNode(ListNode* head, int val);

void DeleteDuplication(ListNode** pHead);

// Question 19
bool MatchRegularExpression(string str, string pattern);

// Question 20
bool IsNumber(string s);

string CutNumString(string& s);

bool ScanInteger(string& s);

bool ScanUnsignedInteger(string& s);
}
