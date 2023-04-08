#include "solution.h"

/*
 * 09. 用两个栈实现队列
 * 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead，
 * 分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回-1)
 */

void solution::CQueue::AppendTail(int value) {
    inputStack.push(value);
}

int solution::CQueue::DeleteHead() {
    if (outputStack.empty()) {
        if (inputStack.empty()) {
            return -1;
        }

        while (!inputStack.empty()) {
            int temp = inputStack.top();
            inputStack.pop();
            outputStack.push(temp);
        }
    }

    const int result = outputStack.top();
    outputStack.pop();
    return result;
}
