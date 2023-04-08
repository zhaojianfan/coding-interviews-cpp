#include <iostream>

#include "data_structure.h"

using namespace ds;

void PrintListNode(ListNode* head) {
    if (head == nullptr) {
        return;
    }

    ListNode* pNode = head;
    while (pNode != nullptr) {
        std::printf("node value = %d\n", pNode->val);
        pNode = pNode->next;
    }
}
