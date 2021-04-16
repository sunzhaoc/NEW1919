/*
 * @Description:
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-10 13:34:55
 * @LastEditTime: 2021-01-10 14:03:47
 * @FilePath: \Leetcode\228.Summary Ranges.cpp
 */
/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 32.36%    O(n) = 
MEMORY: 7.2MB    BEAT:  8.84%    O(n) = 
USED TIME: 25:40
Description: 
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 1) {
            return {to_string(nums[0])};
        }
        vector<string> res;
        int start = 0, end = 0;
        for (int i = 1; i < nums.size(); i ++) {
            if (i != nums.size() - 1) {
                if (nums[i] == nums[i - 1] + 1) {
                    end ++;
                }
                else if (start == end) {
                    res.push_back(to_string(nums[start]));
                    start = i;
                    end = i;
                }
                else {
                    res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                    start = i;
                    end = i;
                }
            }
            else if (nums[i] == nums[i - 1] + 1) {
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[++end]));
            }
            else if (start == end) {
                res.push_back(to_string(nums[end]));
                res.push_back(to_string(nums[++end]));
            }
            else {
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                res.push_back(to_string(nums[++end]));
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    // vector<int> nums = {0,1,2,4,5,7};
    // vector<int> nums = {-1};
    vector<int> nums = {1, 3};
    vector<string> ans = sol.summaryRanges(nums);
    // cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

