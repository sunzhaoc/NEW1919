/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-05 08:37:08
 * @LastEditTime: 2021-03-16 15:02:03
 * @FilePath: \Leetcode\232.Implement Queue using Stacks.cpp
 */
/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
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
#include <stack>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.8MB    BEAT:  62.11%    O(n) = 
USED TIME: 09:53
LAST EDIT TIME: 2021年3月5日8:49:1
Description: Easy
*/

class MyQueue {
public:

    stack<int> A, B;

    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (B.empty()) A.push(x);
        else {
            while(!B.empty()) {
                A.push(B.top());
                B.pop();
            }
            A.push(x);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (A.empty()) {
            int x = B.top();
            B.pop();
            return x;
        }
        else {
            while (!A.empty()) {
                B.push(A.top());
                A.pop();
            }
            int x = B.top();
            B.pop();
            return x;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if (A.empty()) {
            int x = B.top();
            return x;
        }
        else {
            while (!A.empty()) {
                B.push(A.top());
                A.pop();
            }
            int x = B.top();
            return x;
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (A.empty() && B.empty()) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

