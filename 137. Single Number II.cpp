/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-08 20:58:36
 * @LastEditTime: 2021-03-08 21:30:53
 * @FilePath: \Leetcode\137.Single Number II.cpp
 */
/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
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
#include <numeric>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 98.11%    O(n) = 
MEMORY: 9.3MB    BEAT: 77.64s%    O(n) = 
LAST EDIT TIME: 2021年3月8日21:28:33
Description: 
https://leetcode-cn.com/problems/single-number-ii/solution/zhi-chu-xian-yi-ci-de-shu-zi-ii-by-leetcode/
这解法NB大了。
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num: nums) {
            ones = ~ twos & (ones ^ num);
            twos = ~ ones & (twos ^ num);
        }
        return ones;
    }
};


/*
RESULT: Accept
TIME:    12ms    BEAT: 58.14%    O(n) = n
MEMORY: 9.2MB    BEAT: 92.32%    O(n) = 
LAST EDIT TIME: 2021年3月8日21:18:22
Description: 考虑每一位上出现的0和1的次数，如果出现1的次数为3k+1，则证明答案中这一位是1。
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int bit = 0; bit < 32; bit ++) {
            int counter = 0;
            for (int i = 0; i < nums.size(); i ++) {
                counter += (nums[i] >> bit) & 1;
            }
            ans += (counter % 3) << bit;
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {-2,-2,1,1,4,1,4,4,-4,-2};
    int ans = sol.singleNumber(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

