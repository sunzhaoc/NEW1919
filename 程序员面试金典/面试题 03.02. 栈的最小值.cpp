/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-16 14:02:57
 * @LastEditTime: 2021-03-16 14:17:38
 * @FilePath: \Leetcode\demp.cpp
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
TIME:     32ms    BEAT: 46.04%    O(n) = 
MEMORY: 14.7MB    BEAT: 80.83%    O(n) = 
USED TIME: 13:48
LAST EDIT TIME: 2021年3月16日14:17:9
Description: 
*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> st;

    MinStack() {

    }
    
    void push(int x) {
        if (st.empty()) st.push({x, x});
        else st.push({x, x < st.top().second ? x : st.top().second});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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