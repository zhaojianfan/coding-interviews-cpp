#include "solution.h"
#include "data_structure.h"

/*
 * 8. 二叉树的下一个节点
 * 给定一颗二叉树和其中一个节点，如何找出中序遍历序列的下一个节点。
 */

ds::TreeNode* solution::GetNext(TreeNode* pNode) {
    if (pNode == nullptr) {
        return nullptr;
    }

    TreeNode* pNext = nullptr;

    if (pNode->right != nullptr) {
        TreeNode* pRight = pNode->right;
        while (pRight->left != nullptr) {
            pRight = pRight->left;
        }
        pNext = pRight;
    } else if (pNode->parent != nullptr) {
        TreeNode* pCurrent = pNode;
        TreeNode* pParent = pNode->parent;
        while (pParent != nullptr && pCurrent == pParent->right) {
            pCurrent = pParent;
            pParent = pParent->parent;
        }
        pNext = pParent;
    }

    return pNext;
}
