/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-30 13:24:55
 * @LastEditTime: 2020-12-30 14:26:44
 * @FilePath: \Leetcode\剑指 Offer 09. 用两个栈实现队列.cpp
 */

#include <stack>
using namespace std;


/*
RESULT: Accept
TIME:     520ms    BEAT: 72.41%    O(n) = 1
MEMORY: 101.6MB    BEAT: 43.32%    O(n) = 1
Description: 
*/

class CQueue {
public:
    stack<int> stack1, stack2;

    CQueue() {

    }
    
    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if (!stack2.empty()) {
            int ans = stack2.top();
            stack2.pop();
            return ans;
        }

        if (stack1.empty()) return -1;
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int ans = stack2.top();
        stack2.pop();
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */