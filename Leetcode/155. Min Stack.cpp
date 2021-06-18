/*
 * @Description:
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-17 21:08:39
 * @LastEditTime: 2021-03-17 21:21:29
 * @FilePath: \Leetcode\155.Min Stack.cpp
 */
/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
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
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:     32ms    BEAT: 45.87%    O(n) = 
MEMORY: 15.7MB    BEAT: 19.86%    O(n) = 
USED TIME: 07:59
LAST EDIT TIME: 2021年3月17日21:20:16
Description: 二刷。之前是python。栈。
*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> minSt;
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if (minSt.empty()) minSt.push(x);
        else if (x < minSt.top()) minSt.push(x);
        else minSt.push(minSt.top());
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

