/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-01 10:32:49
 * @LastEditTime: 2021-03-01 11:10:53
 * @FilePath: \Leetcode\448.Find All Numbers Disappeared in an Array.cpp
 */
/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
using namespace std;


/*
RESULT: Accept
TIME:     64ms    BEAT: 42.28%    O(n) = 
MEMORY: 31.4MB    BEAT: 41.24%    O(n) = 
LAST EDIT TIME: 2021年3月1日10:58:33
Description: NB！！！
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;

        if (nums.empty()) return nums;

        int n = nums.size();
        for (int i = 0; i < nums.size(); i ++) {
            int index = (nums[i] - 1) % n;
            nums[index] += n;
        }

        for (int i = 0; i < n; i ++) {
            if (nums[i] <= n) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = sol.findDisappearedNumbers(nums);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}
// @lc code=end

