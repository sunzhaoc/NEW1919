/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-03 14:48:59
 * @LastEditTime: 2021-03-17 20:15:57
 * @FilePath: \Leetcode\153.Find Minimum in Rotated Sorted Array.cpp
 */
/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
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
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 82.44%    O(n) = 
MEMORY: 9.7MB    BEAT: 98.01%    O(n) = 
USED TIME: 04:00
LAST EDIT TIME: 2021年3月17日20:14:51
Description: 二刷。二分。
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int res = INT_MAX;

        while (l <= r) {
            int mid = (r - l) / 2 + l;
            res = min(res, nums[mid]);

            // Left is in order
            if (nums[l] <= nums[mid]) {
                res = min(res, nums[l]);
                l = mid + 1;
            }
            // Right
            else if (nums[mid] <= nums[r]) {
                res = min(res, nums[mid]);
                r = mid - 1;
            }
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:    0ms    BEAT: 100.00%    O(n) = logn
MEMORY: 10MB    BEAT:  50.55%    O(n) = 1
USED TIME: 03:54
LAST EDIT TIME: 2021年3月3日14:54:5
Description: 二分查找。本题与33、81题不同在于：有序部分的最小值可以直接取得。我们想要的是无序的部分。
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int L = 0, R = nums.size() - 1, mid;
        while (L <= R) {
            mid = (R - L) / 2 + L;
            ans = min(ans, nums[mid]);

            // 左边有序
            if (nums[L] <= nums[mid]) {
                ans = min(ans, nums[L]);
                L = mid + 1;
            }
            // 右边有序
            else {
                ans = min(ans, nums[R]);
                R = mid - 1;
            }
        }
        return ans;
    }
};

// @lc code=end

