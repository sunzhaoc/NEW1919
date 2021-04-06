/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-16 15:02:32
 * @LastEditTime: 2021-03-16 15:18:08
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
TIME:    212ms    BEAT: 61.82%    O(n) = 
MEMORY: 45.7MB    BEAT: 46.59%    O(n) = 
USED TIME: 07:43
LAST EDIT TIME: 2021年3月16日15:18:11
Description: 
*/

class SortedStack {
public:
    stack<int> st;
    stack<int> tmp;

    SortedStack() {

    }
    
    void push(int val) {
        if (st.empty() || val <= st.top()) st.push(val);
        else {
            while (!st.empty() && val > st.top()) {
                tmp.push(st.top());
                st.pop();
            }
            st.push(val);
            while (!tmp.empty()) {
                st.push(tmp.top());
                tmp.pop();
            }
        }
    }
    
    void pop() {
        if (!st.empty()) st.pop();
    }
    
    int peek() {
        return st.empty() ? -1 : st.top();
    }
    
    bool isEmpty() {
        return st.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
