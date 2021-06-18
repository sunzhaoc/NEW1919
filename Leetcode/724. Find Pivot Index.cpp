/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-15 15:22:25
 * @LastEditTime: 2021-01-15 15:46:44
 * @FilePath: \Leetcode\724.Find Pivot Index.cpp
 */
/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
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
TIME:     28ms    BEAT: 99.95%    O(n) = n
MEMORY: 30.3MB    BEAT: 97.19%    O(n) = 1
LAST EDIT TIME: 2021年1月15日15:46:20
Description: 前缀和。 下面的优化。
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int &i: nums) {
            sum += i;
        }
        
        int left_sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (left_sum == sum - left_sum - nums[i]) return i;
            left_sum += nums[i];
        }
        return -1;
    }
};


/*
RESULT: Accept
TIME:     32ms    BEAT: 99.66%    O(n) = n
MEMORY: 30.1MB    BEAT: 99.95%    O(n) = 1
USED TIME: 13:56
LAST EDIT TIME: 2021年1月15日15:38:16
Description: 
*/

// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         if (nums.size() < 3) return -1;
//         int sum_left = 0, sum_right = 0;

//         int mid = 0;
//         for (int i = 1; i < nums.size(); i ++) {
//             sum_right += nums[i];
//         }
        
//         if (sum_right == sum_left) return 0;

//         while (mid < nums.size() && sum_left != sum_right) {

//             sum_left += nums[mid ++];
//             sum_right -= nums[mid];    
//             if (sum_right == sum_left) return mid;
//         }
        
//         return -1;
//     }
// };


int main() {
    Solution sol;
    vector<int> nums = {1,7,3,6,5,6};
    // vector<int> nums = {1,2,3};
    // vector<int> nums = {-1,-1,-1,0,1,1};
    int ans = sol.pivotIndex(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}


// @lc code=end

