/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-16 14:51:56
 * @LastEditTime: 2021-03-16 14:58:46
 * @FilePath: \Leetcode\dmep.cpp
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.6MB    BEAT:  81.95%    O(n) = 
USED TIME: 05:52
LAST EDIT TIME: 2021年3月16日14:58:27
Description: 
*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> a, b;
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (b.empty()) a.push(x);
        else {
            while (!b.empty()) {
                a.push(b.top());
                b.pop();
            }
            a.push(x);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!b.empty()) {
            int ret = b.top();
            b.pop();
            return ret;
        }
        else {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
            int ret = b.top();
            b.pop();
            return ret;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if (!b.empty()) {
            int ret = b.top();
            // b.pop();
            return ret;
        }
        else {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
            int ret = b.top();
            // b.pop();
            return ret;
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty() && b.empty();
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