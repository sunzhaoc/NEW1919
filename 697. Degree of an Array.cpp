/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-20 21:48:41
 * @LastEditTime: 2021-01-20 22:09:45
 * @FilePath: \Leetcode\697.Degree of an Array.cpp
 */
/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
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
TIME:     52ms    BEAT: 96.31%    O(n) = n
MEMORY: 25.2MB    BEAT: 58.40%    O(n) = n
USED TIME: 13:30
LAST EDIT TIME: 2021年1月20日22:4:19
Description: 哈希。
*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < nums.size(); i ++) {
            // Find it;
            if (map.find(nums[i]) != map.end()) {
                map[nums[i]][0] ++;
                map[nums[i]][2] = i;
                ans = max(ans, map[nums[i]][0]);                
            }
            else {
                map[nums[i]].resize(3);
                map[nums[i]][0] = 1;
                map[nums[i]][1] = i;
                map[nums[i]][2] = i;
                ans = max(ans, map[nums[i]][0]);
            }
        }

        auto it = map.begin();
        vector<int> tmp;
        while (it != map.end()) {
            if (it->second[0] == ans) {
                tmp.push_back(it->first);
            }
            it ++;
        }
        
        int res = INT_MAX;
        for (int i = 0; i < tmp.size(); i ++) {
            res = min(res, map[tmp[i]][2] - map[tmp[i]][1] + 1);
        }
        return res;
    }
};


int main() {
    Solution sol;
    // vector<int> nums = {1,2,2,3,1};
    vector<int> nums = {1,2,2,3,1,4,2};
    int ans = sol.findShortestSubArray(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}
// @lc code=end

