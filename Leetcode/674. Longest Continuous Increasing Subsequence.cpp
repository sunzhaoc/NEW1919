/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start

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
TIME:     12ms    BEAT: 96.64%    O(n) = n
MEMORY: 10.6MB    BEAT: 98.36%    O(n) = 1
USED TIME: 05:46
LAST EDIT TIME: 2021年1月24日9:45:53
Description: 双指针。
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int tmpLen = 1;
        while (r < nums.size()) {
            if (r == l) {
                r ++;
                continue;
            }
            if (nums[r] > nums[r - 1]) {
                tmpLen = r - l + 1;
                r ++;
            }
            else {
                maxLen = max(maxLen, tmpLen);
                tmpLen = 0;
                l = r;
            }
        }
        
        maxLen = max(maxLen, tmpLen);
        return maxLen;
    }
};
// @lc code=end

