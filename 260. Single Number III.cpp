/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-09 19:06:25
 * @LastEditTime: 2021-03-09 19:38:04
 * @FilePath: \Leetcode\260.Single Number III.cpp
 */
/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
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
TIME:     8ms    BEAT: 91.09%    O(n) = 
MEMORY: 9.7MB    BEAT: 69.96%    O(n) = 
LAST EDIT TIME: 2021年3月9日19:37:38
Description: Y总
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int s = 0;
        for (int num: nums) s ^= num;
        int k = 0;
        while (!(s >> k & 1)) k ++;

        int s2 = 0;

        for (int num: nums) {
            if (num >> k & 1) s2 ^= num;
        }

        return {s2, s ^ s2};
    }
};


/*
RESULT: Accept
TIME:    12ms    BEAT: 64.65%    O(n) = 
MEMORY: 9.8MB    BEAT: 51.55%    O(n) = 
USED TIME: 20:37
LAST EDIT TIME: 2021年3月9日19:28:7
Description: 有BUG。
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() == 2) return nums;
        vector<int> res;
        sort(nums.begin(), nums.end());
        int i;
        int tmp = nums[0] ^ nums[1];
        if (tmp != 0) {
            res.emplace_back(nums[0]);
            i = 2;
        }
        else i = 1;

        while (i < nums.size()) {
            tmp = nums[i] ^ nums[i - 1];
            if (tmp != 0) {
                res.emplace_back(nums[i - 1]);
                i ++;
            }
            else i += 2;
        }
        
        if (res.size() == 1) res.emplace_back(nums[nums.size() - 1]);
        return res;
    }
};

// @lc code=end

