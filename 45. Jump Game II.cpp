/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-05 16:12:42
 * @LastEditTime: 2021-03-05 18:33:47
 * @FilePath: \Leetcode\45.Jump Game II.cpp
 */
/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
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
TIME:   12ms    BEAT: 92.51%    O(n) = n
MEMORY: 15MB    BEAT: 92.02%    O(n) = 1
LAST EDIT TIME: 2021年3月5日18:33:23
Description: 
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0;
        int end = 0;
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i ++) {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end) {
                end = maxPos;
                ans ++;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    int ans = sol.(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}
// @lc code=end

