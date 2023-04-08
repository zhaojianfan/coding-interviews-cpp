#include "solution.h"
#include "data_structure.h"

/*
 * 18-1. 删除链表的节点
 * 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
 * 返回删除后的链表的头节点。
 */

ds::ListNode* solution::DeleteNode(ListNode* head, int val) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode* pHead = new ListNode(0);
    pHead->next = head;

    ListNode* pPreNode = pHead;
    ListNode* pNode = head;
    while (pNode != nullptr) {
        if (pNode->val == val) {
            pPreNode->next = pNode->next;
            break;
        }
        pPreNode = pNode;
        pNode = pNode->next;
    }

    return pHead->next;
}


/*
 * 18-2. 删除链表中重复的节点
 * 在一个排序的链表中，删除重复的节点。
 * 返回删除后的链表的头节点。
 */

void solution::DeleteDuplication(ListNode** pHead) {
    if (pHead == nullptr || *pHead == nullptr) {
        return;
    }

    ListNode* pPreNode = nullptr;
    ListNode* pNode = *pHead;

    while (pNode != nullptr) {
        ListNode* pNext = pNode->next;
        bool isDeleted = false;

        if (pNext != nullptr && pNext->val == pNode->val) {
            isDeleted = true;
        }

        if (!isDeleted) {
            pPreNode = pNode;
            pNode = pNext;
        } else {
            int value = pNode->val;
            ListNode* pDeleted = pNode;

            while (pDeleted != nullptr && pDeleted->val == value) {
                pNext = pDeleted->next;
                delete pDeleted;
                pDeleted = pNext;
            }

            if (pPreNode == nullptr) {
                *pHead = pNext;
            } else {
                pPreNode->next = pNext;
            }
            pNode = pNext;
        }
    }
}
