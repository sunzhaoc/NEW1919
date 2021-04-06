/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-07 14:10:36
 * @LastEditTime: 2021-01-07 14:25:40
 * @FilePath: \Leetcode\剑指 Offer 59 - II. 队列的最大值.cpp
 */


#include <queue>
#include <deque>
using namespace std;


/*
RESULT: Accept
TIME:    220ms    BEAT: 54.35%    O(n) = 
MEMORY: 48.2MB    BEAT: 37.43%    O(n) = 
USED TIME: 12:50
Description: 
*/

class MaxQueue {
public:
    queue<int> q;
    deque<int> d;
    MaxQueue() {
    }
    
    int max_value() {
        return d.empty() ? -1 : d.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while(!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
    }
    
    int pop_front() {
        if (q.empty()) return -1;
        int val = q.front();
        while (val == d.front()) d.pop_front();
        q.pop();
        return val;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */