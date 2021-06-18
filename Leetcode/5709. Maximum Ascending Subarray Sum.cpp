/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-21 10:11:19
 * @LastEditTime: 2021-03-21 14:30:18
 * @FilePath: \Leetcode\5709.Maximum Ascending Subarray Sum.cpp
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>




/*
RESULT: Accept
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
LAST EDIT TIME: 2021-03-21 10:34:29
Description: 
*/

using namespace std;
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int res = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] > nums[i - 1]) maxSum += nums[i];
            else {
                res = max(res, maxSum);
                maxSum = nums[i];
            }
        }
        res = max(res, maxSum);
        return res;
    }
};




int main() {
    Solution sol;
    // vector<int> nums = {10, 20, 30, 5, 10, 50};
    // vector<int> nums = {10,20,30,40,50};
    // vector<int> nums = {12,17,15,13,10,11,12};
    vector<int> nums = {100,10,1};
    int ans = sol.maxAscendingSum(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}