/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-16 21:45:33
 * @LastEditTime: 2021-01-18 22:03:26
 * @FilePath: \Leetcode\303.Range Sum Query - Immutable.cpp
 */
/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:     32ms    BEAT: 96.59%    O(n) = 
MEMORY: 16.7MB    BEAT: 98.19%    O(n) = 
USED TIME: 04:31
LAST EDIT TIME: 2021年1月18日22:3:9
Description: 
*/

class NumArray {
public:
    vector<int> tmp;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            tmp.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        // if (i == j) return tmp[i];
        if (i == 0) return tmp[j];
        return (tmp[j] - tmp[i - 1]);
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

