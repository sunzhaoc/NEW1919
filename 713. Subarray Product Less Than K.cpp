/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-15 13:46:51
 * @LastEditTime: 2021-01-15 15:17:45
 * @FilePath: \Leetcode\713.Subarray Product Less Than K.cpp
 */
/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
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
TIME:    116ms    BEAT: 99.76%    O(n) = n
MEMORY: 83.3MB    BEAT: 96.82%    O(n) = 1
LAST EDIT TIME: 2021年1月15日15:6:46
Description: 
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int sum = 1;
        int count = 0, left = 0;

        for (int right = 0; right < nums.size(); right ++) {
            sum *= nums[right];
            while (sum >= k) {
                sum /= nums[left];
                left ++;
            }
            count += (right - left + 1); // 这步有点秀。计算以[v, right]区间, left <= v <= right。
        }

        return count;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {10,5,2,6}; int k = 100;
    // vector<int> nums = {1,1,1}; int k = 0;
    int ans = sol.numSubarrayProductLessThanK(nums, k);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

