/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-13 16:33:09
 * @LastEditTime: 2021-01-13 17:02:18
 * @FilePath: \Leetcode\18.4Sum.cpp
 */
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
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
TIME:    120ms    BEAT: 34.40%    O(n) = n^3
MEMORY: 13.1MB    BEAT: 31.48%    O(n) = logn 空间复杂度主要取决于排序所用的额外空间。
USED TIME: 13:29
LAST EDIT TIME: 2021年1月13日16:56:37
Description: 常规双指针。
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int len = nums.size();

        if (len < 4 || (len == 4 && nums[0] + nums[1] + nums[2] + nums[3] != target)) return {};
        else if (len == 4 && nums[0] + nums[1] + nums[2] + nums[3] == target) return {nums};

        for (int first = 0; first < len; first ++) {
            if (first != 0 && nums[first] == nums[first - 1]) continue;
            
            for (int second = first + 1; second < len; second ++) {
                if (second != first + 1 && nums[second] == nums[second - 1]) continue;

                int third = second + 1;
                int forth = len - 1;

                while (third < forth) {
                    if (nums[first] + nums[second] + nums[third] + nums[forth] > target) forth --;
                    else if (nums[first] + nums[second] + nums[third] + nums[forth] < target) third ++;
                    else {
                        res.push_back({nums[first], nums[second], nums[third], nums[forth]});

                        while (third < forth && nums[forth] == nums[forth - 1]) forth --; 
                        while (third < forth && nums[third] == nums[forth + 1]) third ++; 
                        forth --;
                        third ++;
                    }
                }
            }
        }        
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {-3,-2,-1,0,0,1,2,3};
    vector<vector<int>> ans = sol.fourSum(nums, 0);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i][0] << " "<< ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
    }
    system("pause");
    return 0;
}

// @lc code=end

