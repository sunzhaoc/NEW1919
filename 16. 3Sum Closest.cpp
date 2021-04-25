/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-14 20:12:19
 * @LastEditTime: 2021-01-14 21:05:05
 * @FilePath: \Leetcode\16.3Sum Closest.cpp
 */
/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
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
TIME:    16ms    BEAT: 82.11%    O(n) = n^2
MEMORY: 9.7MB    BEAT: 99.64%    O(n) = logn
LAST EDIT TIME: 2021年1月14日21:3:0
Description: 双指针 优化。
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int distance = 999999;
        int ans;
        for (int i = 0; i < nums.size(); i ++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            
            int l = i + 1;
            int r = nums.size() - 1;
            
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] - target == 0) return target;

                else if (abs(nums[i] + nums[l] + nums[r] - target) < distance) {
                    distance = abs(nums[l] + nums[r] + nums[i] - target);
                    ans = nums[i] + nums[l] + nums[r];
                }

                // 去重。
                if (nums[i] + nums[l] + nums[r] < target) {
                    while (l < r && nums[l] == nums[l + 1]) l ++;
                    l ++;
                }

                else {
                    while (l < r && nums[r] == nums[r - 1]) r --;
                    r --;
                }
            }
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:    28ms    BEAT: 29.28%    O(n) = n^2
MEMORY: 9.7MB    BEAT: 99.66%    O(n) = logn
USED TIME: 21:48
LAST EDIT TIME: 2021年1月14日20:42:24
Description: 双指针。
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int distance = 999999;
        int ans;
        for (int i = 0; i < nums.size(); i ++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            
            int l = i + 1;
            int r = nums.size() - 1;
            
            while (l < r) {
                if (abs(nums[i] + nums[l] + nums[r] - target) < distance) {
                    distance = abs(nums[l] + nums[r] + nums[i] - target);
                    ans = nums[i] + nums[l] + nums[r];
                    if (nums[i] + nums[l] + nums[r] - target > 0) r--;
                    else l ++;
                }
                else {
                    if (nums[i] + nums[l] + nums[r] - target > 0) r--;
                    else l ++;
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {-1,2,1,-4};
    // vector<int> nums = {0, 2, 1, -3};
    int target = 1;
    int  ans = sol.threeSumClosest(nums, target);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

