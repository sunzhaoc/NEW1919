/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-19 16:59:08
 * @LastEditTime: 2021-01-19 17:11:03
 * @FilePath: \Leetcode\628.Maximum Product of Three Numbers.cpp
 */
/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
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
TIME:   60ms    BEAT: 90.41%    O(n) = nlogn
MEMORY: 27MB    BEAT: 79.51%    O(n) = logn
USED TIME: 08:47
LAST EDIT TIME: 2021年1月19日17:10:15
Description: 
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[0] >= 0) return nums[n - 1] * nums[n - 2] * nums[n - 3];
        int A = nums[n - 1] * nums[n - 2] * nums[n - 3];
        A = max(A, nums[0] * nums[1] * nums[n - 1]);
        return A;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {};
    int ans = sol.(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

