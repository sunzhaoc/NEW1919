/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-30 19:27:35
 * @LastEditTime: 2021-03-30 19:50:48
 * @FilePath: \Leetcode\287.Find the Duplicate Number.cpp
 */
/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
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
TIME:     12ms    BEAT: 58.22%    O(n) = 
MEMORY: 10.8MB    BEAT: 44.50%    O(n) = 
USED TIME: 16:32
LAST EDIT TIME: 2021年3月30日19:46:2
Description: my idea is：判断左右区间哪个更紧密。数字分布更紧密的区间
即(nums[i] - nums[j]) / (i - j) 更小，则重复的数处于这一区间。
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] == nums[r] || nums[mid] == nums[l]) return nums[mid];
            if ((nums[mid] - nums[l]) / (mid - l) > (nums[r] - nums[mid]) / (r - mid)) l = mid;
            else r = mid;
        }
        return -1;
    }
};


// @lc code=end

