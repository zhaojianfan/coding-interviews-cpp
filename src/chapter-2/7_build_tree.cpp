#include "solution.h"
#include "data_structure.h"

/*
 * 07. 重建二叉树
 * 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 */

ds::TreeNode* solution::BuildTree(vector<int>& preOrder, vector<int>& inOrder) {
    if (preOrder.empty() || inOrder.empty()) {
        return nullptr;
    }

    return ConstructCore(preOrder, inOrder);
}

ds::TreeNode* solution::ConstructCore(vector<int>& preOrder, vector<int>& inOrder) {
    // 通过前序遍历找到根节点
    const int rootValue = preOrder[0];
    TreeNode* root = new TreeNode(rootValue);

    // 若该树只有根节点，则直接返回
    if (preOrder.size() == 1 && inOrder.size() == 1 && preOrder[0] == inOrder[0]) {
        return root;
    }

    // 找到根节点在中序遍历中的位置
    auto rootInOrder = inOrder.begin();
    while (rootInOrder < inOrder.end() && *rootInOrder != rootValue) {
        ++rootInOrder;
    }

    // 划分左右子树
    const int leftChildLength = rootInOrder - inOrder.begin();
    vector<int> leftChildInOrder(inOrder.begin(), rootInOrder);
    vector<int> leftChildPreOrder(preOrder.begin() + 1, preOrder.begin() + 1 + leftChildLength);

    const int rightChildLength = preOrder.size() - leftChildLength - 1;
    vector<int> rightChildInOrder(rootInOrder + 1, inOrder.end());
    vector<int> rightChildPreOrder(preOrder.end() - rightChildLength, preOrder.end());

    // 通过递归分配子节点
    if (leftChildLength > 0) {
        root->left = ConstructCore(leftChildPreOrder, leftChildInOrder);
    }

    if (rightChildLength > 0) {
        root->right = ConstructCore(rightChildPreOrder, rightChildInOrder);
    }

    return root;
}
