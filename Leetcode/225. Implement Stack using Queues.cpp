/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-05 09:02:59
 * @LastEditTime: 2021-03-05 10:10:11
 * @FilePath: \Leetcode\225.Implement Stack using Queues.cpp
 */
/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.6MB    BEAT:  93.15%    O(n) = 
USED TIME: 04:04
LAST EDIT TIME: 2021年3月5日10:9:52
Description: 
*/

class MyStack {
public:
    queue<int> A;
    int num = 0;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        A.push(x);
        for (int i = 0; i < num; i ++) {
            int tmp = A.front();
            A.pop();
            A.push(tmp);
        }
        num ++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = A.front();
        A.pop();
        num --;
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return A.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return A.empty();
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 31.95%    O(n) = 
MEMORY: 6.6MB    BEAT: 91.97%    O(n) = 
USED TIME: 05:30
LAST EDIT TIME: 2021年3月5日9:52:10
Description: 简化了一下。
*/

class MyStack {
public:

    queue<int> a, b;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        b.push(x);
        while (!a.empty()) {
            b.push(a.front());
            a.pop();
        }
        swap(a, b);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = a.front();
        a.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return a.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty();
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.8MB    BEAT:  49.27%    O(n) = 
USED TIME: 29:46
LAST EDIT TIME: 2021年3月5日9:36:46
Description: 
*/

class MyStack {
public:
    queue<int> A, B;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if (B.empty()) {
            A.push(x);
        }
        else {
            B.push(x);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (A.empty()) {
            while (1) {
                int x = B.front();
                B.pop();
                if (!B.empty()) A.push(x);
                else return x;
            }
        }
        else {
            while (1) {
                int x = A.front();
                A.pop();
                if (!A.empty()) B.push(x);
                else return x;
            }
        }
    }
    
    /** Get the top element. */
    int top() {
        return A.empty() ? B.back() : A.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return A.empty() && B.empty() ? true : false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// @lc code=end

