#pragma once

namespace ds {
// The implementation of LinkedList
struct ListNode {
    int val;
    ListNode* next;

    explicit ListNode(int x) : val(x), next(nullptr) {}

    explicit ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void PrintListNode(ListNode* head);


// The implementation of BinaryTree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};
}
