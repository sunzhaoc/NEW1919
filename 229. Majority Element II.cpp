/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-24 15:39:47
 * @LastEditTime: 2020-12-24 17:09:50
 * @FilePath: \Leetcode\229.Majority Element II.cpp
 */
/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:     32ms    BEAT: 69.75%    O(n) = 2n
MEMORY: 15.7MB    BEAT: 48.92%    O(n) = 1
Description: 摩尔投票法。So Hard！本题是求个数大于长度1/3的所有数。假设数组长度为n,那么我们稍微思考可以得出结论个数超过3/n的数不会超过2个。
https://leetcode-cn.com/problems/majority-element-ii/solution/liang-fu-dong-hua-yan-shi-mo-er-tou-piao-fa-zui-zh/
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ticket01 = 0, ticket02 = 0;
        int person01 = nums[0], person02 = nums[0];

        for (int mem: nums) {
            if (person01 == mem) {
                ticket01 ++;
                continue;
            }
            
            if (person02 == mem) {
                ticket02 ++;
                continue;
            }
            
            if (ticket01 == 0) {
                person01 = mem;
                ticket01 ++;
                continue;
            }

            if (ticket02 == 0) {
                person02 = mem;
                ticket02 ++;
                continue;
            }

            ticket01 --;
            ticket02 --;
        }

        int count1 = 0, count2 = 0;
        for (int mem: nums) {
            if (mem == person01) count1 ++;
            else if (mem == person02) count2 ++;
        }
        
        vector<int> res;
        if (count1 > nums.size() / 3) res.push_back(person01);
        if (count2 > nums.size() / 3) res.push_back(person02);
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> ans = sol.majorityElement(nums);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}
// @lc code=end

