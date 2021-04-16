/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-31 09:40:46
 * @LastEditTime: 2021-03-31 14:25:55
 * @FilePath: \Leetcode\217.Contains Duplicate.cpp
 */
/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
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
TIME:     32ms    BEAT: 77.78%    O(n) = 
MEMORY: 19.5MB    BEAT: 56.94%    O(n) = 
USED TIME: 04:12
LAST EDIT TIME: 2021年3月31日9:45:35
Description: 二刷。之前是python。
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i ++) {
            int a = s.size();
            s.insert(nums[i]);
            int b = s.size();
            if (a == b) return true;
        }
        return false;
    }
};

// @lc code=end

