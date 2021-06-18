/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-14 15:53:11
 * @LastEditTime: 2021-01-14 16:54:49
 * @FilePath: \Leetcode\170.Two Sum III - Data structure design.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
using namespace std;


/*
RESULT: Accept
TIME:    112ms    BEAT: 97.38%    O(n) = 
MEMORY: 23.6MB    BEAT: 75.90%    O(n) = 
LAST EDIT TIME: 2021年1月14日16:39:16
Description: 方法Easy，一些multiset和尾迭代器的用法需要掌握。
*/

class TwoSum {
private:
    multiset<int> nums;

public:
    /** Initialize your data structure here. */
    TwoSum() {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if (nums.empty()) return false;

        auto p = nums.begin(), q = --nums.end();
        while (p != q) {
            int sum = *p + *q;
            if (sum < value) ++p;
            else if (sum > value) --q;
            else return true;
        }
        return false;
    }
};


/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
