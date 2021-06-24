/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-04 19:40:01
 * @LastEditTime: 2021-06-22 16:06:40
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 30. 包含min函数的栈.cpp
 */

#include <stack>
using namespace std;

/*
RESULT: Accept
TIME:     48ms    BEAT: 22.92%    O(n) = 1
MEMORY: 15.2MB    BEAT: 43.19%    O(n) = 1
USED TIME: 06:10
Description: 双堆。
*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stack1, stack2;
    MinStack() {

    }
    
    void push(int x) {
        stack1.push(x);
        if (stack2.empty() || x <= stack2.top()) stack2.push(x);
    }
    
    void pop() {
        if(stack1.top() == stack2.top()) stack2.pop();
        stack1.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int min() {
        return stack2.top()
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */