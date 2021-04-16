/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-03 15:04:13
 * @LastEditTime: 2021-03-03 15:12:08
 * @FilePath: \Leetcode\154.Find Minimum in Rotated Sorted Array II.cpp
 */
/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
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
TIME:    4ms    BEAT: 95.63%    O(n) = logn
MEMORY: 12MB    BEAT: 58.77%    O(n) = 1
USED TIME: 05:49
LAST EDIT TIME: 2021年3月3日15:11:20
Description: 二分查找。
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0, R = nums.size() - 1, mid;
        int ans = INT_MAX;

        while (L <= R) {
            mid = (R - L) / 2 + L;
            ans = min(ans, nums[mid]);

            // 主要是这一步
            if (nums[L] == nums[mid]) {
                ans = min(ans, nums[mid]);
                L ++;
                continue;
            }
            
            if (nums[L] <= nums[mid]) {
                ans = min(ans, nums[L]);
                L = mid + 1;
            }
            else {
                ans = min(ans, nums[mid]);
                R = mid - 1;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    // vector<int> nums = {4,5,6,7,0,1,2};
    // int ans = sol.search(nums, 3);
    vector<int> nums = {1,3,5};
    int ans = sol.findMin(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

