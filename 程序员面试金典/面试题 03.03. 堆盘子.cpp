/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-16 14:18:30
 * @LastEditTime: 2021-03-16 14:51:14
 * @FilePath: \Leetcode\demo.cpp
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
TIME:     56ms    BEAT: 87.87%    O(n) = 
MEMORY: 27.4MB    BEAT: 42.28%    O(n) = 
USED TIME: 29:42
LAST EDIT TIME: 2021年3月16日14:48:46
Description: 题目表达太差。
*/

class StackOfPlates {
public:
    vector<stack<int>> plates;
    int cap;

    StackOfPlates(int x) {
        cap = x;
        plates.push_back(stack<int>());
    }
    
    void push(int val) {
        if (cap == 0) return;
        if (plates.size() == 0 || plates.back().size() == cap) {
            plates.push_back(stack<int>());
        }
        plates.back().push(val);
        
    }
    
    int pop() {
        if (cap == 0) return -1;
        if (plates.size() == 0 || plates.back().size() == 0) return -1;
        int ret = plates.back().top();
        plates.back().pop();
        if (plates.back().size() == 0) plates.pop_back();
        return ret;
    }
    
    int popAt(int index) {
        if (cap == 0 || index >= plates.size() || plates[index].size() == 0) return -1; 
        int ret = plates[index].top();
        plates[index].pop();
        if (plates[index].size() == 0) plates.erase(plates.begin() + index);
        return ret;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */