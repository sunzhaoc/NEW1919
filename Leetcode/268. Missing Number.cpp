/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-24 09:01:18
 * @LastEditTime: 2021-03-24 09:16:40
 * @FilePath: \Leetcode\268.丢失的数字.cpp
 */
/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
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
TIME:     12ms    BEAT: 98.89%    O(n) = n
MEMORY: 17.6MB    BEAT: 50.30%    O(n) = 1
LAST EDIT TIME: 2021年3月24日9:16:30
Description: 利用数学的知识来解。
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = (1 + nums.size()) * nums.size() / 2;
        for (int x: nums) sum -= x;
        return sum;
    }
};


/*
RESULT: Accept
TIME:     24ms    BEAT: 61.06%    O(n) = nlogn
MEMORY: 17.4MB    BEAT: 90.21%    O(n) = logn
USED TIME: 03:04
LAST EDIT TIME: 2021年3月24日9:9:50
Description: 
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] != 0) return 0;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] != nums[i - 1] + 1) return i;
        }
        return nums.size();
    }
};

// @lc code=end

