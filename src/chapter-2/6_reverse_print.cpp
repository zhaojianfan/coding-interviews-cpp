#include "solution.h"

/*
 * 06. 从尾到头打印链表
 * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
 */

vector<int> solution::ReversePrint(ListNode* head) {
    ListNode* pNode = head;
    std::stack<ListNode*> nodes;

    while (pNode != nullptr) {
        nodes.push(pNode);
        pNode = pNode->next;
    }

    vector<int> result;

    while (!nodes.empty()) {
        pNode = nodes.top();
        result.push_back(pNode->val);
        nodes.pop();
    }

    return result;
}
