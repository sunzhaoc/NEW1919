/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-29 21:18:04
 * @LastEditTime: 2020-12-29 22:24:20
 * @FilePath: \Leetcode\330.Patching Array.cpp
 */
/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */

// @lc code=start

#include <iostream>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:      8ms    BEAT: 93.51%    O(n) = m + log n
MEMORY: 11.5MB    BEAT: 29.29%    O(n) = 1
Description: 
https://leetcode-cn.com/problems/patching-array/solution/an-yao-qiu-bu-qi-shu-zu-tan-xin-suan-fa-b4bwr/
*/

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long total = 0; // 累加的总和
        int count = 0, index = 0;
        
        while (total < n) {
            if (index < nums.size() && nums[index] <= total + 1) total += nums[index ++];
            else {
                total = total + total + 1;
                count ++;
            }
        }
        return count;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 5, 10};
    int ans = sol.minPatches(nums, 20);
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

