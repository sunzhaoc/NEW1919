/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-15 12:37:38
 * @LastEditTime: 2021-01-15 13:43:42
 * @FilePath: \Leetcode\523.Continuous Subarray Sum.cpp
 */
/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
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
TIME:     28ms    BEAT: 100.00%    O(n) = n
MEMORY: 25.5MB    BEAT:  85.35%    O(n) = min(n, k)
USED TIME: 53:03
LAST EDIT TIME: 2021年1月15日13:33:40
Description: 哈希表 + 前缀和。 我反正不知道怎么写了那么久。各种边界条件要注意。
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // 小于2直接跳过
        if (nums.size() < 2) return false;

        // 因为分母不能为0，故要单独讨论。注意题目nums均>=0,故只有0 + 0 = 0！！！
        if (k == 0) {
            for (int i = 1; i < nums.size(); i ++) {
                if (nums[i - 1] == nums[i] && nums[i] == 0) {
                    return true;
                }
            }
            return false;
        }
        

        int sum = 0;
        unordered_map<int, int> map; 
        for (int i = 0; i < nums.size(); i ++) {
            sum = (sum + nums[i]) % k;

            // 避免第一个是0，0是任何数的倍数，但长度为1，不满足。
            if (i > 0 && sum == 0) return true;
            else {
                auto it = map.find(sum);
                // Not found
                if (it == map.end()) {
                    map[sum] = i;
                }
                // Find
                else {
                    //
                    if (i - it->second >= 2){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


int main() {
    Solution sol;
    // vector<int> nums = {23,2,4,6,7}; int k = -6; // true
    // vector<int> nums = {1,0,1,0,1}; int k = 4; // false
    // vector<int> nums = {0,1}; int k = 1;
    // vector<int> nums = {0}; int k = -1; // false
    // vector<int> nums = {0,1}; int k = 1; // true
    // vector<int> nums = {0,0, 0, 0, 0, 0 }; int k = 1; // true
    // vector<int> nums = {1,0}; int k = 2; // false
    vector<int> nums = {0,0}; int k = 0; // false
    // vector<int> nums = {0,0}; int k = 1; // true
    // vector<int> nums = {0,1,0,3,0,4,0,4,0}; int k = 5; // false
    
    bool ans = sol.checkSubarraySum(nums, k);
    cout << ans << endl;
    
    system("pause");
    return 0;
}
// @lc code=end

