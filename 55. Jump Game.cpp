/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-05 15:59:34
 * @LastEditTime: 2021-03-05 16:12:20
 * @FilePath: \Leetcode\55.Jump Game.cpp
 */
/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
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
using namespace std;


/*
RESULT: Accept
TIME:     20ms    BEAT: 43.57%    O(n) = 
MEMORY: 12.5MB    BEAT: 70.47%    O(n) = 
USED TIME: 10:16
LAST EDIT TIME: 2021年3月5日16:11:0
Description: 有点意思。维护一个最大的index，如果遍历到超过最大的index,则return false.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int id = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (i > id) return false;
            id = max(id, i + nums[i]);
            if (id >= nums.size() - 1) return true;
        }
        return true;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    bool ans = sol.canJump(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

